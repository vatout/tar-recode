/*
** header.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 23:55:23 2016 Antoine Baché
** Last update Sun Jan 10 07:06:58 2016 Antoine Baché
*/

#include "my_archive.h"

int	get_checksum(t_header *head)
{
  char	*ptr;
  int	i;
  int	res_a;

  ptr = (char *)head;
  i = -1;
  res_a = 0;
  while (++i < 512)
    res_a += ptr[i];
#ifdef DEBUG
  printf("Chksum = %d\n", res_a);
  printf("Octal Chksum = %o\n", res_a);
#endif
  return (res_a);
}

int	get_file_type(struct stat *stat)
{
  if (S_ISDIR(stat->st_mode))
    return ('5');
  else if (S_ISLNK(stat->st_mode))
    return ('2');
  else if (S_ISFIFO(stat->st_mode))
    return ('6');
  else if (S_ISCHR(stat->st_mode))
    return ('3');
  else if ((long)stat->st_nlink > 1)
    return ('1');
  return ('0');
}

int	check_name(t_header *head, char *arg)
{
  if (head->type_flag[0] == '5' && arg[strlen(arg) - 1] != '/')
    {
      if (sprintf(head->name, "%s/", arg) < 0)
	return (1);
    }
  else if (sprintf(head->name, "%s", arg) < 0)
    return (1);
  return (0);
}

int		infos_header(t_header *head, char *arg)
{
  struct stat	*stats;

  if ((stats = malloc(sizeof(struct stat))) == NULL ||
      stat(arg, stats) == -1 ||
      sprintf(head->size, "%0*lo", 11, (long)stats->st_size) < 0 ||
      sprintf(head->mode, "%0*lo", 7, (long)stats->st_mode) < 0 ||
      sprintf(head->mtime, "%0*lo", 11, (long)stats->st_mtime) < 0 ||
      (head->type_flag[0] = get_file_type(stats)) < 0  ||
      check_name(head, arg) == 1 ||
      strncpy(head->magic, "ustar  ", 8) == NULL ||
      strncpy(head->version, " \0", 2) == NULL ||
      sprintf(head->uid, "%0*o", 7, stats->st_uid) < 0 ||
      sprintf(head->gid, "%0*o", 7, stats->st_gid) < 0 ||
      strncpy(head->uname, (getpwuid(stats->st_uid))->pw_name, 32) == NULL ||
      strncpy(head->gname, (getgrgid(stats->st_gid))->gr_name, 32) == NULL)
    return (1);
  if ((head->type_flag[0] == '3' || head->type_flag[0] == '4') &&
      ((sprintf(head->devmajor, "%d", major(stats->st_rdev)) < 0 ||
	sprintf(head->devminor, "%d", minor(stats->st_rdev)) < 0)))
    return (1);
  else if (head->type_flag[0] == '2' &&
      readlink(head->type_flag, head->linkname, 100) < 0)
    return (1);
  free(stats);
  return (0);
}

t_header	*create_header(char *arg)
{
  t_header	*head;

  if ((head = malloc(sizeof(t_header))) == NULL)
    return (NULL);
  memset(head, '\0', sizeof(t_header));
  if (sprintf(head->chksum, "        ") < 0)
    return (NULL);
  if (infos_header(head, arg) == 1)
    return (NULL);
  head->mode[1] = '0';
  head->mode[2] = '0';
  head->chksum[7] = ' ';
  if (sprintf(head->chksum, "%0*o", 6, get_checksum(head)) < 0)
    return (NULL);
  return (head);
}
