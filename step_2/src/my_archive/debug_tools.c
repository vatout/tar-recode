/*
** debug_tools.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 21:00:23 2016 Antoine Baché
** Last update Fri Jan  8 22:09:45 2016 Antoine Baché
*/

#include "my_archive.h"

void	show_args(char **args)
{
  int	i;

  i = -1;
  printf("SHOW ARGS :\n");
  while (args[++i] != NULL)
    printf("Args[%d] = \"%s\"\n", i, args[i]);
}
