/*
** my_setline.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 23:45:29 2015 Antoine Baché
** Last update Fri Nov 20 06:52:26 2015 Antoine Baché
*/

#include "../include/my.h"

void	set_pos(t_bunny_position *tmp, t_bunny_position *tmp2, t_bunny_position *pos, int *tab)
{
  t_bunny_ini	*file;
  int		width;
  int		height;

  file = bunny_load_ini("file.ini");
  width = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  height = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  bunny_delete_ini(file);
  tmp[0].x = pos[tab[0]].x + ((tab[3] - STEP) / 2) + STEP * tab[1];
  tmp[0].y = pos[tab[0]].y * STEP / 3 + ((tab[2] + STEP) / 2);
  tmp[1].x = pos[tab[0] + 1].x + ((tab[3] - STEP) / 2) + STEP * (tab[1] + 1);
  tmp[1].y = pos[tab[0] + 1].y * STEP / 3 + ((tab[2] + STEP) / 2);
  if (tab[0] <  height * width - 6)
    {
      tmp2[0].x = tmp[0].x;
      tmp2[0].y = tmp[0].y;
      tmp2[1].x = pos[tab[0 + 6]].x + (tab[3] / 2 ) + STEP * (tab[1]) - STEP;
      tmp2[1].y = pos[tab[0] + 6].y * (STEP) / 3 + ((tab[2] + 2 * STEP) / 2);
    }
}

int			my_setline(t_bunny_pixelarray *array, t_bunny_position *pos, t_color *color)
{
  t_bunny_ini		*file;
  t_bunny_position	*tmp;
  t_bunny_position	*tmp2;
  int			width;
  int			height;
  int			*tab;

  if ((tab = malloc(sizeof(int) * 5)) == NULL)
    return (1);
  if ((tmp = bunny_malloc(sizeof(t_bunny_pixelarray) * 2)) == NULL)
    return (1);
  if ((tmp2 = bunny_malloc(sizeof(t_bunny_pixelarray) * 2)) == NULL)
    return (1);
  tab[0] = 0;
  tab[2] = SIZE_X;
  tab[3] = SIZE_X;
  file = bunny_load_ini("file.ini");
  width = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  height = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  while (tab[0] < width * height - 1)
    {
      tab[1] = 0;
      while (tab[1] < width - 1)
	{
	  color->full = 16777215;
	  set_pos(tmp, tmp2, pos, tab);
	  printf("tmp[0].x = %d tmp[0].y = %d\n", tmp[0].x, tmp[0].y);
	  printf("tmp[1].x = %d tmp[1].y = %d\n", tmp[1].x, tmp[1].y);
	  printf("tmp2[0].x = %d tmp2[0].y = %d\n", tmp2[0].x, tmp2[0].y);
	  printf("tmp2[1].x = %d tmp2[1].y = %d\n", tmp2[1].x, tmp2[1].y);
	  printf("tab[0] = %d calc = %d\n", tab[0], (height - 1) * width);
	  tekline(array, tmp, color);
	  color->full = 3456788;
	  if (tab[0] < (height - 1) * width)
	    tekline(array, tmp2, color);
	  tab[1] += 1;
	  tab[0] += 1;
	  printf("j = %d\n", tab[1]);
	}
      if (tab[1] != 0)
	{
	  set_pos(tmp, tmp2, pos, tab);
	  tekline(array, tmp2, color);
	}
      printf("i = %d\n", tab[0]);
      tab[2] += STEP;
      tab[3] -= STEP;
      tab[0] += 1;
    }
  bunny_delete_ini(file);
  bunny_free(tmp);
  bunny_free(tmp2);
  return (0);
}
