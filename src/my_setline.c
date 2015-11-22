/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Sun Nov 22 17:25:44 2015 Antoine Baché
*/

#include "../include/my.h"

void	set_posg(t_position *data, int *tab)
{
  data->tmp1[0].x = (data->posg[tab[0]].x +
    ((tab[3] - data->stepx) / 2) + data->stepx * tab[1]) -
    data->stepx;
  data->tmp1[0].y = data->posg[tab[0]].y * data->stepy / 3 +
    (3 * (tab[2] + data->stepy) / 8);
  data->tmp1[1].x = data->posg[tab[0] + 1].x +
    ((tab[3] - data->stepx) / 2) + data->stepx * (tab[1] + 1) -
    data->stepx;
  data->tmp1[1].y = data->posg[tab[0] + 1].y *
    data->stepy / 3 + (3 * (tab[2] + data->stepy) / 8);
  if (tab[0] <  data->height * data->width - data->width)
    {
      data->tmp2[0].x = data->tmp1[0].x;
      data->tmp2[0].y = data->tmp1[0].y;
      data->tmp2[1].x = data->pos[tab[0] + data->width].x +
	(tab[3] / 2) + data->stepx * tab[1] - 2 * data->stepx;
      data->tmp2[1].y = data->posg[tab[0] + data->width].y *
	data->stepy / 3 + (3 * (tab[2] + 2 * data->stepy) / 8);
    }
}

void	set_pos(t_position *data, int *tab)
{
  data->tmp1[0].x = data->pos[tab[0]].x +
    ((tab[3] - data->stepx) / 2) + data->stepx * tab[1] -
    data->stepx;
  data->tmp1[0].y = data->pos[tab[0]].y * data->stepy / 3 +
    (3 * (tab[2] + data->stepy) / 8);
  data->tmp1[1].x = data->pos[tab[0] + 1].x +
    ((tab[3] - data->stepx) / 2) + data->stepx * (tab[1] + 1) -
    data->stepx;
  data->tmp1[1].y = data->pos[tab[0] + 1].y * data->stepy / 3 +
    (3 * (tab[2] + data->stepy) / 8);
  if (tab[0] <  data->height * data->width - data->width)
    {
      data->tmp2[0].x = data->tmp1[0].x;
      data->tmp2[0].y = data->tmp1[0].y;
      data->tmp2[1].x = data->pos[tab[0] + data->width].x +
	(tab[3] / 2) + data->stepx * tab[1] - 2 * data->stepx;
      data->tmp2[1].y = data->pos[tab[0] + data->width].y *
	data->stepy / 3 + (3 * (tab[2] + 2 * data->stepy) / 8);
    }
}

int	my_setline(t_bunny_pixelarray *array, t_position *position,
		   t_color *color)
{
  int	*tab;

  if ((tab = bunny_malloc(sizeof(int) * 5)) == NULL)
    return (1);
  if ((position->tmp1 = bunny_malloc(sizeof(t_bunny_pixelarray) * 2)) == NULL)
    return (1);
  if ((position->tmp2 = bunny_malloc(sizeof(t_bunny_pixelarray) * 2)) == NULL)
    return (1);
  tab[0] = 0;
  tab[2] = SIZE_X;
  tab[3] = SIZE_X;
  draw_ground(array, position, color, tab);
  tab[0] = 0;
  tab[2] = SIZE_X;
  tab[3] = SIZE_X;
  color->full = 9560692;
  draw_vertical(array, position, color, tab);
  tab[0] = 0;
  tab[2] = SIZE_X;
  tab[3] = SIZE_X;
  color->full = 16777215;
  draw_shape(array, position, color, tab);
  return (0);
}

void	draw_ground(t_bunny_pixelarray *pix, t_position *position,
		    t_color *color, int *tab)
{
  while (tab[0] < position->width * position->height - 1)
    {
      tab[1] = 0;
      while (tab[1] < position->width - 1)
	{
	  set_posg(position, tab);
	  tekline(pix, position->tmp1, color);
	  if (tab[0] < (position->height - 1) * position->width &&
	      position->height > 1)
	    tekline(pix, position->tmp2, color);
	  tab[1] += 1;
	  tab[0] += 1;
	}
      if (tab[1] != 0)
	{
	  set_posg(position, tab);
	  tekline(pix, position->tmp2, color);
	}
      tab[2] += position->stepy;
      tab[3] -= position->stepx;
      tab[0] += 1;
    }
}

void	draw_shape(t_bunny_pixelarray *pix, t_position *position,
		   t_color *color, int *tab)
{
  while (tab[0] < position->width * position->height - 1)
    {
      tab[1] = 0;
      while (tab[1] < position->width - 1)
	{
	  set_pos(position, tab);
	  tekline(pix, position->tmp1, color);
	  if (tab[0] < (position->height - 1) * position->width)
	    tekline(pix, position->tmp2, color);
	  tab[1] += 1;
	  tab[0] += 1;
	}
      if (tab[1] != 0 && position->height > 1)
	{
	  set_pos(position, tab);
	  tekline(pix, position->tmp2, color);
	}
      tab[2] += position->stepy;
      tab[3] -= position->stepx;
      tab[0] += 1;
    }
}
