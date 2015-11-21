/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Sat Nov 21 15:45:10 2015 Antoine Baché
*/

#include "../include/my.h"

void	set_posg(t_position *data, int *tab)
{
  data->tmp1[0].x = data->posg[tab[0]].x +
    ((tab[3] - STEPX) / 2) + STEPX * tab[1];
  data->tmp1[0].y = data->posg[tab[0]].y * STEPY / 3 + ((tab[2] + STEPY) / 2);
  data->tmp1[1].x = data->posg[tab[0] + 1].x +
    ((tab[3] - STEPX) / 2) + STEPX * (tab[1] + 1);
  data->tmp1[1].y = data->posg[tab[0] + 1].y *
    STEPY / 3 + ((tab[2] + STEPY) / 2);
  if (tab[0] <  data->height * data->width - 6)
    {
      data->tmp2[0].x = data->tmp1[0].x;
      data->tmp2[0].y = data->tmp1[0].y;
      data->tmp2[1].x = data->posg[tab[0] + 6].x +
	(tab[3] / 2 ) + STEPX * tab[1] - STEPX;
      data->tmp2[1].y = data->posg[tab[0] + 6].y *
	(STEPY) / 3 + ((tab[2] + 2 * STEPY) / 2);
    }
}

void	set_pos(t_position *data, int *tab)
{
  data->tmp1[0].x = data->pos[tab[0]].x +
    ((tab[3] - STEPX) / 2) + STEPX * tab[1];
  data->tmp1[0].y = data->pos[tab[0]].y * STEPY / 3 + ((tab[2] + STEPY) / 2);
  data->tmp1[1].x = data->pos[tab[0] + 1].x +
    ((tab[3] - STEPX) / 2) + STEPX * (tab[1] + 1);
  data->tmp1[1].y = data->pos[tab[0] + 1].y * STEPY / 3 + ((tab[2] + STEPY) / 2);
  if (tab[0] <  data->height * data->width - 6)
    {
      data->tmp2[0].x = data->tmp1[0].x;
      data->tmp2[0].y = data->tmp1[0].y;
      data->tmp2[1].x = data->pos[tab[0] + 6].x +
	(tab[3] / 2 ) + STEPX * tab[1] - STEPX;
      data->tmp2[1].y = data->pos[tab[0] + 6].y *
	(STEPY) / 3 + ((tab[2] + 2 * STEPY) / 2);
    }
}

int			my_setline(t_bunny_pixelarray *array, t_position *position, t_color *color)
{
  int			*tab;

  if ((tab = malloc(sizeof(int) * 5)) == NULL)
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

void	draw_ground(t_bunny_pixelarray *pix, t_position *position, t_color *color, int *tab)
{
  while (tab[0] < position->width * position->height - 1)
    {
      tab[1] = 0;
      while (tab[1] < position->width - 1)
	{
	  set_posg(position, tab);
	  tekline(pix, position->tmp1, color);
	  if (tab[0] < (position->height - 1) * position->width)
	    tekline(pix, position->tmp2, color);
	  tab[1] += 1;
	  tab[0] += 1;
	}
      if (tab[1] != 0)
	{
	  set_posg(position, tab);
	  tekline(pix, position->tmp2, color);
	}
      tab[2] += STEPY;
      tab[3] -= STEPX;
      tab[0] += 1;
    }
}

void	draw_shape(t_bunny_pixelarray *pix, t_position *position, t_color *color, int *tab)
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
      if (tab[1] != 0)
	{
	  set_pos(position, tab);
	  tekline(pix, position->tmp2, color);
	}
      tab[2] += STEPY;
      tab[3] -= STEPX;
      tab[0] += 1;
    }
}
