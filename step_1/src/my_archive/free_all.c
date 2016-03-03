/*
** free_all.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 23:29:49 2016 Antoine Baché
** Last update Sun Jan 10 03:07:12 2016 Antoine Baché
*/

#include "my_archive.h"

int	free_dir(int ret, char *path)
{
  free(path);
  return (ret);
}

void	free_args(char **args)
{
  int	i;

  i = - 1;
  while (args[++i] != NULL)
    free(args[i]);
  if (args != NULL)
    free(args);
}
