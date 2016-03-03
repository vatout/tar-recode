/*
** my_unarchive.h for Rush1 in /Rush1/step1/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 20:21:19 2016 Antoine Baché
** Last update Sat Jan  9 23:42:00 2016 Antoine Baché
*/

#ifndef MY_UNARCHIVE_H_
# define MY_UNARCHIVE_H_
# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif /* !BUFF_SIZE */

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "tar_struct.h"

void	show_header(t_header *);
int	chksum_calc(t_header *);
int	check_chksum(t_header *);

#endif /* !MY_UNARCHIVE_ */
