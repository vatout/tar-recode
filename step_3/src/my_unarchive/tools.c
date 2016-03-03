/*
** tools.c for Rush1 in /Rush1/step_3/src/my_unarchive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 12:15:21 2016 Antoine Baché
** Last update Sun Jan 10 12:58:02 2016 Antoine Baché
*/

#include "my_unarchive.h"

int		create_dir(t_header *head)
{
  mode_t	mode;

#ifdef DEBUG
  printf("CREATE DIR\nDir = \"%s\"\n", head->mode);
#endif
  mode = strtol(head->mode, NULL, 8);
  if (mkdir(head->name, mode) == -1)
    return (1);
  return (0);
}



int		extract_file(int fd, t_header *head)
{
  size_t	size;
  int		mode;
  int		file;
  char		*buff;

  size = strtol(head->size, NULL, 8);
  mode = strtol(head->mode, NULL, 8);
  if ((buff = malloc(sizeof(char) * size)) == NULL ||
      (read(fd, buff, size) < 0) ||
      (file = open(head->name, O_CREAT | O_TRUNC | O_WRONLY, mode)) < 0 ||
      write(file, buff, size) < 0)
    return (1);
  size = 512 - size % 512;
  if (read(fd, buff, size) < 0 || close(file) < 0)
    return (1);
  free(buff);
  return (0);
}
