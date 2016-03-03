/*
** unarchive.c for Rush1 in /Rush1/step_1/src/my_unarchive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  9 02:22:41 2016 Antoine Baché
** Last update Sun Jan 10 13:03:41 2016 Antoine Baché
*/

#include "my_unarchive.h"

int	check_rights_unarchive(char *av)
{
  char	*buff;

#ifdef DEBUG
  printf("CHECK RIGHTS UNARCHIVE\nArchive = %s\n", av);
#endif
  if (access(av, F_OK | R_OK) < 0)
    {
      write(2, "Cannot find or read file ", 25);
      write(2, av, strlen(av));
      write(2, "\n", 1);
      return (1);
    }
  if ((buff = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
    return (1);
  if (access(getcwd(buff, BUFF_SIZE - 1), F_OK | R_OK | W_OK) == -1)
    {
      free(buff);
      write(2, "Cannot write in current directory\n", 34);
      return (1);
    }
  free(buff);
  return (0);
}

int	read_header(int fd, t_header *head)
{
  if (read(fd, head, sizeof(t_header)) < 0 || check_chksum(head) == 1)
    return (1);
#ifdef DEBUG
  printf("READ HEADER\n");
  show_header(head);
#endif
  return (0);
}

int		unarchive(char *av)
{
  t_header	head;
  int		fd;

  if (check_rights_unarchive(av) == 1)
    return (1);
  if ((fd = open(av, O_RDONLY)) < 0)
    {
      write(2, "Error while reading file\n", 25);
      return (1);
    }
  while (read_header(fd, &head) != 1)
    {
      if (head.type_flag[0] == '5')
	create_dir(&head);
      else
	extract_file(fd, &head);
    }
  return (0);
}

int	main_unarchive(int ac, char **av)
{
  if (ac != 2 || unarchive(av[1]) == 1)
    {
      write(2, "Usage : ./my_unarchive archive_file\n", 36);
      return (1);
    }
#ifdef DEBUG
  printf("Unarchive state : OK\nEverything went right\n");
#endif
  return (0);
}
