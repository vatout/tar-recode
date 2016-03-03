/*
** chksum.c for Rush1 in /Rush1/step_1/src/my_unarchive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  9 23:20:16 2016 Antoine Baché
** Last update Sun Jan 10 00:14:48 2016 Antoine Baché
*/

#include "my_unarchive.h"

int	chksum_calc(t_header *header)
{
  int	i;
  char	*str;
  int	sum;

  i = -1;
  str = (char *)header;
  sum = 0;
  while (++i < (int)sizeof(t_header))
    {
      if (i > 147 && i <= 154)
	sum += ' ';
      else
	sum += str[i];
    }
  return (sum);
}

int	check_chksum(t_header *header)
{
  char	chksum[8];
  int	i;

  i = -1;
  chksum[7] = ' ';
  sprintf(chksum, "%0*o", 6, chksum_calc(header));
  while (++i < 8)
    {
      if (chksum[i] != header->chksum[i])
	return (1);
    }
#ifdef DEBUG
  printf("CHKSUM : OK\n\n");
#endif
  return (0);
}
