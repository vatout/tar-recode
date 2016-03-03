/*
** options.c for Rush1 in /Rush1/step_3/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 10:29:14 2016 Antoine Baché
** Last update Sun Jan 10 10:46:09 2016 Antoine Baché
*/

#include "my_tar.h"

int	x_select(t_opt *args)
{
  args->x = 1;
  return (0);
}

int	c_select(t_opt *args)
{
  args->c = 1;
  return (0);
}

int	v_select(t_opt *args)
{
  args->v = 1;
  return (0);
}

int	t_select(t_opt *args)
{
  args->t = 1;
  return (0);
}

int	f_select(t_opt *args)
{
  args->f = 1;
  return (0);
}
