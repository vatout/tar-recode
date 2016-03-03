/*
** debug_tools.c for Rush1 in /Rush1/step_1/src/my_unarchive
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  9 22:56:36 2016 Antoine Baché
** Last update Sat Jan  9 23:10:13 2016 Antoine Baché
*/

#include "my_unarchive.h"

void	show_header(t_header *header)
{
  printf("Name: \"%s\"\n", header->name);
  printf("Mode: \"%s\"\n", header->mode);
  printf("UID: \"%s\"\n", header->uid);
  printf("GID: \"%s\"\n", header->gid);
  printf("Size: \"%s\"\n", header->size);
  printf("mtime: \"%s\"\n", header->mtime);
  printf("Chksum: \"%s\"\n", header->chksum);
  printf("Type_flag: \"%s\"\n", header->type_flag);
  printf("Linkname: \"%s\"\n", header->linkname);
  printf("Magic: \"%s\"\n", header->magic);
  printf("Version: %s\n", header->version);
  printf("Uname: \"%s\"\n", header->uname);
  printf("Gname: \"%s\"\n", header->gname);
  printf("DevMajor: \"%s\"\n", header->devmajor);
  printf("DevMinor: \"%s\"\n", header->devminor);
  printf("Prefix: \"%s\"\n", header->prefix);
  printf("End: \"%s\"\n", header->end);
}
