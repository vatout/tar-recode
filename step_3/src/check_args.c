/*
** check_args.c for Rush1 in /Rush1/step_3/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 09:32:54 2016 Antoine Baché
** Last update Sun Jan 10 10:45:44 2016 Antoine Baché
*/

#include "my_tar.h"

int	p_select(t_opt *args)
{
  args->p = 1;
  return (0);
}

int	my_exit_args(char *options, tab array)
{
  write(2, "'\n", 2);
  if (options != NULL)
    free(options);
  if (array != NULL)
    free(array);
  return (-1);
}

tab	arg_selector(void)
{
  tab	array;

  if ((array = malloc(sizeof(int *) * 6)) == NULL)
    return (NULL);
  array[0] = &x_select;
  array[1] = &c_select;
  array[2] = &v_select;
  array[3] = &f_select;
  array[4] = &t_select;
  array[5] = &p_select;
  return (array);
}

int	look_options(t_opt *args)
{
  if (args->f == 0 && write(2, "Missing f option\n", 17) != -2)
    return (1);
  if (args->x == args->c && write(2, "Specify either c or x\n", 22) != -2)
    return (1);
  return (0);
}

int	check_args_main(char *av, int j, t_opt *args)
{
  char	*options;
  tab	array;
  int	i;

  i = 0;
  if ((options = strdup("xcvftp")) == NULL)
    return (my_exit_args(options, NULL));
  if ((array = arg_selector()) == NULL)
    return (my_exit_args(options, array));
  while (options[i] != av[j] && (i < 6) && (++i));
  if (i < 6)
    array[i](args);
  else
    {
      write(2, "my_tar: invalid option -- '", 27);
      write(2, &av[j], 1);
      return (my_exit_args(options, array));
    }
  if (av[j + 1] != '\0')
    check_args_main(av, j + 1, args);
  if (look_options(args) == 1)
    return (1);
  free(options);
  free(array);
  return (0);
}
