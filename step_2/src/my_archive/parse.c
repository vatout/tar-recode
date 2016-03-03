/*
** parse.c for Rush1 in /Rush1/step1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 20:37:40 2016 Antoine Baché
** Last update Sat Jan  9 17:56:22 2016 Antoine Baché
*/

#include "my_archive.h"

char	**check_perm(char **args)
{
  int	i;
  char	*buff;

  i = 1;
  if ((buff = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
    return (NULL);
  if (access(getcwd(buff, BUFF_SIZE - 1), F_OK | R_OK | W_OK) == -1)
    {
      free(buff);
      write(2, "Cannot write in current directory\n", 34);
      return (NULL);
    }
  free(buff);
  while (args[++i] != NULL)
    if ((access(args[i], F_OK | R_OK) < 0) &&
	(args = remove_double(args, i - 1)) == NULL)
      return (NULL);
#ifdef DEBUG
  printf("CHECK PERM : in\n");
  show_args(args);
  printf("CHECK PERM : out\n\n");
#endif
  return (args);
}

char	**remove_double(char **args, int k)
{
  int	i;

  if (args[k + 2] == NULL)
    {
      args[k + 1] = NULL;
      return (args);
    }
  while (args[++k + 1] != NULL && (i = -1) != -2)
    {
      free(args[k]);
      if ((args[k] = malloc(sizeof(char) * (strlen(args[k + 1]) + 1))) == NULL)
	return (NULL);
      while (args[k + 1][++i] != '\0' && (args[k][i] = args[k + 1][i]));
      args[k][i] = '\0';
    }
  if (args[k] != NULL)
    free(args[k]);
  args[k] = NULL;
#ifdef DEBUG
  printf("REMOVE DOUBLE : in\n");
  show_args(args);
  printf("REMOVE DOUBLE : out\n\n");
#endif
  return (args);
}

char	**check_double(char **args, int ac)
{
  int	i;
  int	k;

  i = -1;
  while (args[++i] != NULL && (k = i) != -2)
    while (args[++k] != NULL && k < ac - 1)
      if ((strcmp(args[i], args[k]) == 0) &&
	  (args = remove_double(args, k - 1)) == NULL)
	return (NULL);
#ifdef DEBUG
  printf("CHECK DOUBLE : in\n");
  show_args(args);
  printf("CHECK DOUBLE : out\n\n");
#endif
  return (args);
}

char	**get_all_args(int ac, char **av)
{
  char	**args;
  int	i;
  int	j;

  if ((args = malloc(sizeof(char *) * (ac + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < ac && (j = -1))
    {
      if ((args[i] = malloc(sizeof(char) * (strlen(av[i]) + 1)))== NULL)
	return (NULL);
      while (av[i][++j] != '\0' && (args[i][j] = av[i][j]));
      args[i][j] = '\0';
    }
  args[i] = NULL;
#ifdef DEBUG
  printf("GET_ALL_ARGS : in\n");
  show_args(args);
  printf("GET_ALL_ARGS : out\n\n");
#endif
  return (args);
}

char	**parse_args(int ac, char **av)
{
  char	**args;

  if ((args = get_all_args(ac, av)) == NULL ||
      (args = check_double(args, ac)) == NULL ||
      (args = check_perm(args)) == NULL)
    return (NULL);
  return (args);
}
