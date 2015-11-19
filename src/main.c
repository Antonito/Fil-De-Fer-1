/*
** main.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 13:55:54 2015 Antoine Baché
** Last update Thu Nov 19 18:03:47 2015 Antoine Baché
*/

#include "../include/my.h"

void	free_all(t_bunny_position *pos, t_color *color)
{
  free(pos);
  free(color);
}

int			main()
{
  t_bunny_window	*screen;
  t_bunny_pixelarray	*array;
  t_bunny_position	*pos;
  t_color		*color;

  if ((pos = bunny_malloc(sizeof(t_bunny_position)*2)) == NULL)
    return (1);
  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  if ((pos = filereader(pos)) == NULL)
    return (1);
  array = bunny_new_pixelarray(1024, 768);
  screen = bunny_start(1024, 768, 0, "Fil de fer 1");
  my_square(array, color);
  color->full = 16777215;
  my_setline(array, pos, color);
  bunny_blit(&screen->buffer, &array->clipable, NULL);
  bunny_display(screen);
  bunny_loop(screen, 60, screen);
  bunny_stop(screen);
  free_all(pos, color);
  return (0);
}
