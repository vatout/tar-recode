/*
** errors.c for Rush1 in /Rush1/step1/src/my_archive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  8 20:26:19 2016 Antoine Baché
** Last update Fri Jan  8 20:31:35 2016 Antoine Baché
*/

#include "my_archive.h"

int	env_error()
{
  write(2, "Missing environnement\n", 22);
  return (1);
}

int	usage_error()
{
  write(2, "my_archive: Usage: ", 19);
  write(2, "./my_archive archive_file file1 [file2 ... fileN]\n", 50);
  return (1);
}
