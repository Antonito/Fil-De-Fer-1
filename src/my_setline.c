/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Thu Nov 19 18:02:51 2015 Antoine Baché
*/

#include "../include/my.h"

void	my_setpos(t_bunny_position *tmp, t_bunny_position *pos, int i)
{
  tmp[0].x = pos[i].x;
  tmp[0].y = pos[i].y;
  tmp[1].x = pos[i + 1].x;
  tmp[1].y = pos[i + 1].y;
}

int			my_setline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  int			i;
  int			j;
  int			height;
  int			width;
  t_bunny_ini		*file;
  t_bunny_position	*tmp;

  i = 0;
  file = bunny_load_ini("file.ini");
  height = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  width = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  bunny_delete_ini(file);
  if ((tmp = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return (1);
  return (0);
}
