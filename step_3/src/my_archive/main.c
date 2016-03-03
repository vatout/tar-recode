/*
** main.c for Rush1 in Rush1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 20:18:19 2016 Antoine Baché
** Last update Sun Jan 10 10:50:11 2016 Antoine Baché
*/

#include "my_archive.h"

int		my_archive(int ac, char **av)
{
  char		**args;
  t_count	count;

  count.characters = 0;
  count.blocks = 0;
  if ((args = parse_args(ac, av)) == NULL || create_file(args, 1, &count) == 1)
    {
      printf("ERROR\n");
      return (1);
    }
  free_args(args);
  return (0);
}

int	main_archive(int ac, char **av)
{
  if (ac < 3 && usage_error())
    return (1);
  if (my_archive(ac, av) == 1)
    return (1);
#ifdef DEBUG
  printf("Archive state : OK\nEverything went right\n");
#endif
  return (0);
}
