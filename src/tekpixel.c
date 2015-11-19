/*
** tekpixel.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 13:42:40 2015 Antoine Baché
** Last update Wed Nov 18 11:20:13 2015 Antoine Baché
*/

#include "../include/my.h"

void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  t_color	*tmp;

  tmp = (t_color*)pix->pixels + pos[0].x + pos[0].y * pix->clipable.clip_width;
  tmp->full = color->full;
}
