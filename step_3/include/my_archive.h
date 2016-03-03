/*
** my_archive.h for Rush1 in /Rush1/step1/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 20:21:19 2016 Antoine Baché
** Last update Sun Jan 10 09:10:40 2016 Antoine Baché
*/

#ifndef MY_ARCHIVE_H_
# define MY_ARCHIVE_H_
# define UNUSED __attribute__((unused))
# define BUFF_SIZE 4096
# define READ_RIGHTS 00666
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif /* !_DEFAULT_SOURCE */

# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "tar_struct.h"

typedef struct s_count
{
  int		blocks;
  int		characters;
}		t_count;

int		my_archive(int, char **);
int		main_archive(int, char **);
int		check_name(t_header *, char *);
char		*set_fullpath(char *, char *, char *);
int		write_dir_header(char *, int, t_count *);
int		write_file_header(char *, int, t_count *);
int		free_dir(int, char *);
int		is_dir(char *, char *);
int		analyse_dir(DIR *, int, t_count *, char *);
int		open_dir(char *, int, t_count *, t_header *);
int		open_file(char *, int, t_count *, t_header *);
int		pad_file(int, t_count *);
int		infos_header(t_header *, char *);
int		write_file(int, int, t_count *);
int		get_file_type(struct stat *);
t_header	*create_header(char *);
int		create_file(char **, int, t_count *);
void		show_args(char **);
char		**check_perm(char **);
char		**remove_double(char **, int);
char		**check_double(char **, int);
char		**get_all_args(int, char **);
char		**parse_args(int, char **);
int		env_error();
int		usage_error();
void		free_args(char **);

#endif /* !MY_ARCHIVE_ */
