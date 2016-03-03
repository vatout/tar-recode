/*
** select_file.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  9 19:42:50 2016 Antoine Baché
** Last update Sun Jan 10 06:35:26 2016 Antoine Baché
*/

#include "my_archive.h"

int		is_dir(char *name, char *path)
{
  char		*full_path;
  struct stat	stats;

  if ((full_path = malloc(strlen(name) + strlen(path) + 2)) == NULL)
    return (-1);
  if (path[strlen(path) - 1] == '/')
    {
      if (sprintf(full_path, "%s%s", path, name) < 0)
	return (-1);
    }
  else
    if (sprintf(full_path, "%s/%s", path, name) < 0)
      return (-1);
#ifdef DEBUG
  printf("Path = \"%s\"\nName = \"%s\"\n", path, name);
  printf("Full Path = %s\n", full_path);
#endif
  if (stat(full_path, &stats) < 0)
    return (free_dir(-1, full_path));
  if (S_ISREG(stats.st_mode))
    return (free_dir(0, full_path));
  else if (S_ISDIR(stats.st_mode))
    return (free_dir(1, full_path));
  return (free_dir(2, full_path));
}

int	analyse_dir(DIR *dir, int tar, t_count *count, char *path)
{
  char		*full_path;
  struct dirent	*directory;
  static int	loop = 0;
  int		is_directory;

  if (++loop && loop >= 40000 && write(2, "Too many files\n", 15) > -2)
    return (0);
  if ((full_path = NULL) == 0 &&
      ((directory = readdir(dir)) == NULL || path == NULL))
    return (0);
  if (strcmp(directory->d_name, "..") == 0 ||
      strcmp(directory->d_name, ".") == 0)
    return (analyse_dir(dir, tar, count, path));
  if ((is_directory = is_dir(directory->d_name, path)) == -1 ||
      ((full_path = set_fullpath(directory->d_name, path, full_path))) == NULL)
    return (0);
  if (is_directory == 0)
    write_file_header(full_path, tar, count);
  else if (is_directory == 1)
    write_dir_header(full_path, tar, count);
  if (path != NULL && directory != NULL)
    return (analyse_dir(dir, tar, count, path));
  return (0);
}

int	open_dir(char *args, int fd, t_count *count, t_header *header)
{
  DIR	*dir;

#ifdef DEBUG
  printf("OPEN DIR : %s\n", args);
#endif
  count->characters += 512;
  if (write(fd, header, sizeof(t_header)) < 0)
    return (1);
  if ((dir = opendir(args)) == NULL ||
      analyse_dir(dir, fd, count, args) == 1 ||
      closedir(dir) < 0)
    return (1);
  return (0);
}

int	open_file(char *args, int fd, t_count *count, t_header *header)
{
  int	file;

#ifdef DEBUG
  printf("OPEN FILE : %s\n", args);
#endif
  if (write(fd, header, sizeof(t_header)) < 0)
    return (1);
  if ((file = open(args, O_RDONLY)) < 0 ||
      write_file(file, fd, count) == 1 ||
      close(file) < 0)
    return (1);
  return (0);
}
