/*
** my_square.c for fdf1 in /Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 10:10:01 2015 Antoine Baché
** Last update Sat Nov 21 18:27:35 2015 Antoine Baché
*/

#include "../include/my.h"

void			my_square(t_bunny_pixelarray *pix, t_color *color)
{
  int			i;
  int			j;
  t_bunny_position	*pos;

  j = 0;
  i = 0;
  color->full = 0;
  if ((pos = malloc(sizeof(t_bunny_position)*2)) == NULL)
    return;
  while (i < 768)
    {
      pos[0].y = i;
      while (j < 1024)
	{
	  pos[0].x = j;
	  tekpixel(pix, pos, color);
	  j++;
	}
      j = 0;
      i++;
    }
}
