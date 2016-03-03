/*
** create_file.c for Rush1 in /Rush1/step_1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 23:26:53 2016 Antoine Baché
** Last update Sun Jan 10 07:46:58 2016 Antoine Baché
*/

#include "my_archive.h"

int		write_file(int file, int tar, t_count *count)
{
  int		check;
  int		tmp_c;
  int		tmp_b;
  char		buff[BUFF_SIZE];

  count->characters += 512;
  tmp_c = 0;
  while ((check = read(file, &buff, BUFF_SIZE - 1)) > 0)
    {
      if (write(tar, &buff, check) < 0)
	return (1);
      tmp_c += check;
    }
  tmp_b = tmp_c / 512 + 1;
  while (tmp_c < tmp_b * 512)
    {
      if (write(tar, "\0", 1) < 0)
	return (1);
      tmp_c++;
    }
  count->characters += tmp_c;
  count->blocks += tmp_c / 512 + 1;
  if (check < 0)
    return (1);
  return (0);
}

int	pad_file(int fd, t_count *count)
{
#ifdef DEBUG
  printf("PAD FILE: IN\ncharacters = %d Blocks = %d\n", count->characters,
	 count->blocks);
#endif
  if ((count->characters - count->blocks * 512) != 0)
    {
      while (count->characters < count->blocks * 512)
	{
	  if ((write(fd, "\0", 1)) < 0)
	    return (1);
	  count->characters++;
	}
    }
  if (count->blocks % 20 != 0)
    {
      count->blocks++;
      return (pad_file(fd, count));
    }
#ifdef DEBUG
  printf("PAD FILE: OUT\ncharacters = %d Blocks = %d\n", count->characters,
	 count->blocks);
#endif
  return (0);
}

int		create_file(char **args, int i, t_count *count)
{
  t_header	*header;
  int		fd;

  if ((fd = open(args[1], O_WRONLY | O_CREAT | O_TRUNC, READ_RIGHTS)) < 0)
    return (1);
  while (args[++i] != NULL)
    {
      if ((header = create_header(args[i])) == NULL)
	return (1);
      if (header->type_flag[0] == '0' &&
	  open_file(args[i], fd, count, header) == 1)
	return (1);
      else if (header->type_flag[0] == '5' &&
	  open_dir(args[i], fd, count, header) == 1)
	return (1);
      free(header);
    }
  if (pad_file(fd, count) == 1 || close(fd) < 0)
    return (1);
  return (0);
}
