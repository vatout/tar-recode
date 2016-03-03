/*
** my_tar.h for Rush1 in /Rush1/step_3/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 09:05:26 2016 Antoine Baché
** Last update Sun Jan 10 11:21:15 2016 Antoine Baché
*/

#ifndef MY_TAR_H
# define MY_TAR_H
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif /* !_DEFAULT_SOURCE */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_opt
{
  char		x;
  char		c;
  char		v;
  char		f;
  char		t;
  char		p;
}		t_opt;

typedef int	(**tab)(t_opt *);

char	**cpy_av(char **, char **, int);
int	main_archive(int, char **);
int	main_unarchive(int, char **);
int	start_program(int, t_opt *, char **);
void	set_args(t_opt *);
int	look_options(t_opt *);
int	t_select(t_opt *);
int	f_select(t_opt *);
int	v_select(t_opt *);
int	c_select(t_opt *);
int	x_select(t_opt *);
int	p_select(t_opt *);
int	my_exit_args(char *, tab);
tab	arg_selector(void);
int	check_args_main(char *, int, t_opt *);

#endif /* !MY_TAR_H */
