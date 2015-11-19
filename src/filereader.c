/*
** filereader.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 14:50:25 2015 Antoine Baché
** Last update Thu Nov 19 18:03:14 2015 Antoine Baché
*/

#include "../include/my.h"

void	prepare_my_pos(t_bunny_position *pos, int i)
{
  pos->x = pos->x;
  pos->y = -(pos->y);
}

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
    return ;
  while (i < width * height)
    {
      z = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "data", i));
      tekllproject(&pos[i], i%width, i/height, z);
      prepare_my_pos(&pos[i], i);
      ++i;
    }
  bunny_delete_ini(file);
  return (pos);
}
