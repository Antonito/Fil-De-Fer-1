/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Sat Nov 21 16:58:03 2015 Antoine Baché
*/

#include "../include/my.h"

void	set_posv(t_position *data, int *tab)
{
  data->tmp1[0].x = data->posg[tab[0]].x +
    ((tab[3] - STEPX) / 2) + STEPX * tab[1];
  data->tmp1[0].y = data->posg[tab[0]].y * STEPY / 3 + ((tab[2] + STEPY) / 2);
  data->tmp1[1].x = data->posg[tab[0]].x +
    ((tab[3] - STEPX) / 2) + STEPX * tab[1];
  data->tmp1[1].y= data->pos[tab[0]].y * STEPY / 3 + ((tab[2] + STEPY) / 2);
}

void	draw_vertical(t_bunny_pixelarray *pix, t_position *position,
		      t_color *color, int *tab)
{
  while (tab[0] < position->width * position->height - 1)
    {
      tab[1] = 0;
      while (tab[1] < position->width - 1)
	{
	  set_posv(position, tab);
	  tekline(pix, position->tmp1, color);
	  tab[1] += 1;
	  tab[0] += 1;
	}
      if (tab[1] != 0)
	{
	  set_posv(position, tab);
	  tekline(pix, position->tmp1, color);
	}
      tab[2] += STEPY;
      tab[3] -= STEPX;
      tab[0] += 1;
    }
}
