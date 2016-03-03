/*
** main.c for Rush1 in /home/bache_a/work/Prog_Elem/Rush1/step_3/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 08:54:17 2016 Antoine Baché
** Last update Sun Jan 10 11:58:52 2016 Antoine Baché
*/

#include "my_tar.h"

void	set_args(t_opt *arg)
{
  arg->x = 0;
  arg->c = 0;
  arg->v = 0;
  arg->f = 0;
  arg->t = 0;
  arg->p = 0;
}

int	usage_error_main(void)
{
  write(2, "Usage : ./my_tar [xcvftp] [ARG...]\n", 35);
#ifdef DEBUG
  printf("my_tar state : KO\n");
#endif
  return (1);
}

char	**cpy_av(char **cpy, char **av, int ac)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  k = 0;
  while (++i < ac)
    {
      j = -1;
      if (i == 1)
	++i;
      if ((cpy[k] = malloc(sizeof(char) * ((int)strlen(av[i]) + 1))) == NULL)
	return (NULL);
      while (++j < (int)strlen(av[i]))
	cpy[k][j] = av[i][j];
      cpy[k][j] = '\0';
      k++;
    }
  cpy[k] = NULL;
  return (cpy);
}

int	start_program(int ac, t_opt *arg, char **av)
{
  char	**copy_av;

  if ((copy_av = malloc(sizeof(char *) * (ac + 1))) == NULL ||
      (copy_av = cpy_av(copy_av, av, ac)) == NULL)
    return (1);
  if (arg->c == 1 && main_archive(ac - 1, copy_av) == 1)
    return (1);
  else if (arg->x == 1 && main_unarchive(ac - 1, copy_av) == 1)
    return (1);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_opt	list_args;

  if (*env == NULL)
    {
#ifdef DEBUG
      printf("my_tar state : KO\n");
#endif
      write(2, "Missing environnement\n", 22);
      return (1);
    }
  set_args(&list_args);
  if (ac < 3 || check_args_main(av[1], 0, &list_args) == -1)
    return (usage_error_main());
  if (start_program(ac, &list_args, av) == 1)
    return (1);
#ifdef DEBUG
  printf("my_tar state : OK\n");
#endif
  return (0);
}
