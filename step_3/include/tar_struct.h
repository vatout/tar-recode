/*
** tar_struct.h for Rush1 in /Rush1/step_1/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 23:59:19 2016 Antoine Baché
** Last update Sun Jan 10 07:06:35 2016 Antoine Baché
*/

#ifndef TAR_STRUCT_H_
# define TAR_STRUCT_H_

typedef struct	s_header
{
  char		name[100];
  char		mode[8];
  char		uid[8];
  char		gid[8];
  char		size[12];
  char		mtime[12];
  char		chksum[8];
  char		type_flag[1];
  char		linkname[100];
  char		magic[6];
  char		version[2];
  char		uname[32];
  char		gname[32];
  char		devmajor[8];
  char		devminor[8];
  char		prefix[155];
  char		end[12];
}		t_header;

#endif /* !TAR_STRUCT_H_ */
