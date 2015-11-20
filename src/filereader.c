/*
** filereader.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 14:50:25 2015 Antoine Baché
** Last update Fri Nov 20 06:54:53 2015 Antoine Baché
*/

#include "../include/my.h"

t_bunny_position	*filereader(t_bunny_position *pos)
{
  t_bunny_ini		*file;
  int			height;
  int			width;
  int			i;
  int			z;

  i = 0;
  file = bunny_load_ini("file.ini");
  width = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  height = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  if ((pos = bunny_malloc(sizeof(t_bunny_position) * ((width * height)))) == NULL)
    return (NULL);
  while (i < width * height)
    {
      z = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "data", i));
      tekllproject(&pos[i], i%width, i/height, z);
      ++i;
    }
  bunny_delete_ini(file);
  return (pos);
}
