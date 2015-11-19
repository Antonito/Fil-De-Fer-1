/*
** tekline.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 10:03:58 2015 Antoine Baché
** Last update Thu Nov 19 18:02:36 2015 Antoine Baché
*/

#include "../include/my.h"

void	tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  float	a;
  float	b;

  a = ((float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x));
  b = (float)(pos[0].y - pos[0].x * a);
  while (pos[0].y != pos[1].y && pos[0].x == pos[1].x)
    {
      tekpixel(pix, pos, color);
      if (pos[0].y != pos[1].y)
	pos[0].y += ((pos[1].y > pos[0].y) ? 1 : -1);
    }
  while (pos[0].x != pos[1].x)
    {
      tekpixel(pix, pos, color);
      if (pos[0].x != pos[1].x)
	pos[0].x += ((pos[1].x > pos[0].x) ? 1 : -1);
      while (pos[0].y != (int)(a * pos[0].x + b) && pos[1].y != pos[0].y)
	{
	  tekpixel(pix, pos, color);
	  if (pos[0].y != pos[1].y)
	    pos[0].y += (((int)(a * pos[0].x + b) > pos[0].y) ? 1 : -1);
	}
    }
}
