/*
** tools.c for Rush1 in /Rush1/step_1/src/my_unarchive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 10 12:15:21 2016 Antoine Baché
** Last update Sun Jan 10 12:25:09 2016 Antoine Baché
*/

int	create_dir(int fd, t_header *head)
{
  int	file;
  mod_t	mode;

#ifdef DEBUG
  printf("CREATE DIR\nDir = \"%s\"\n", head->mode);
#endif
  mode = strtol(head->mode, NULL, 8);
  if (mkdir(head->name, mode) == -1)
    return (1);
  return (0);
}

int	create_file(int fd, t_header *head)
{
  return (0);
}
