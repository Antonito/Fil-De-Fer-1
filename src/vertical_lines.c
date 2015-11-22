/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Sun Nov 22 17:26:55 2015 Antoine Baché
*/

#include "../include/my.h"

void	set_posv(t_position *data, int *tab)
{
  data->tmp1[0].x = (data->posg[tab[0]].x +
		     ((tab[3] - data->stepx) / 2) +
		     data->stepx * tab[1]) - data->stepx;
  data->tmp1[0].y = data->posg[tab[0]].y * data->stepy /3 +
    (3 * (tab[2] + data->stepy) / 8);
  data->tmp1[1].x = (data->pos[tab[0]].x +
		     ((tab[3] - data->stepx) / 2) +
		     data->stepx * tab[1]) - data->stepx;
  data->tmp1[1].y = data->pos[tab[0]].y * data->stepy / 3 +
    (3 * (tab[2] + data->stepy) / 8);
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
      tab[2] += position->stepy;
      tab[3] -= position->stepx;
      tab[0] += 1;
    }
}
