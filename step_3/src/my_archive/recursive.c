/*
** recursive.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 03:05:13 2016 Antoine Baché
** Last update Sun Jan 10 12:00:50 2016 Antoine Baché
*/

#include "my_archive.h"

char	*set_fullpath(char *name, char *path, char *full_path)
{
  if ((full_path = malloc(strlen(name) + strlen(path) + 2)) == NULL)
    return (NULL);
  if (path[strlen(path) - 1] == '/')
    {
      if (sprintf(full_path, "%s%s", path, name) < 0)
	return (NULL);
    }
  else if (sprintf(full_path, "%s/%s", path, name) < 0)
    return (NULL);
  return (full_path);
}

int	write_file_header(char *name, int tar, t_count *count)
{
  t_header	*header;

  if ((header = create_header(name)) == NULL)
    return (1);
#ifdef DEBUG
  printf("%s is a file\n", name);
#endif
  open_file(name, tar, count, header);
#ifdef DEBUG
  printf("OPEN FILE OK\n");
#endif
  free(header);
  free(name);
  return (0);
}

int	write_dir_header(char *name, int tar, t_count *count)
{
  t_header	*header;

  if ((header = create_header(name)) == NULL)
    return (1);
#ifdef DEBUG
  printf("%s is a dir\n", name);
#endif
  open_dir(name, tar, count, header);
#ifdef DEBUG
  printf("OPEN DIR OK\n");
#endif
  free(header);
  free(name);
  return (0);
}
