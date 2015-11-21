/*
** main.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 13:55:54 2015 Antoine Baché
** Last update Sat Nov 21 16:52:07 2015 Antoine Baché
*/

#include "../include/my.h"

void	free_all(t_bunny_position *pos, t_color *color)
{
  bunny_free(pos);
  bunny_free(color);
}

int	my_display(t_bunny_pixelarray *array, t_position *position, t_bunny_ini *file, t_color *color)
{
  my_square(array, color);
  color->full = 6250335;
  if (filereader(position, file) == 1)
    return (1);
  if (get_ground(position, file) == 1)
    return (1);
  if ((my_setline(array, position, color) == 1))
    return (1);
  return (0);
}

t_bunny_response	my_loop(void *position)
{
  if (my_display(((t_position *)position)->pix,
		 ((t_position *)position),
		 ((t_position *)position)->file,
		 ((t_position *)position)->color) == 1)
    return (-1);
  bunny_blit(&((t_position *)position)->screen->buffer,
	     &((t_position *)position)->pix->clipable, NULL);
  bunny_display(((t_position *)position)->screen); 
  return (GO_ON);
}

int	load_map(t_position *position, int ac, char **av)
{
  if (ac == 1)
    {
      my_putstr_err("./fdf1: must take exactly one parameter.\n");
      return (1);
    }
  else if ((position->file = bunny_load_ini(av[1])) == NULL)
    {
      my_putstr_err("./fdf1: cannot open or read file ");
      my_putstr_err(av[1]);
      my_putstr_err(".\n");
      return (1);
    }
  return (0);
}

int			main(int ac, char **av)
{
  t_position		*position;
  t_bunny_loop		loop;


  if ((position = bunny_malloc(sizeof(t_position))) == NULL)
    return (1);
  if (load_map(position, ac, av) == 1)
    return (1);
  loop = &my_loop;
  position->pix = bunny_new_pixelarray(SIZE_X, SIZE_Y);
  position->screen = bunny_start(SIZE_X, SIZE_Y, 0, "Fil de fer 1");
  if ((position->color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_loop(position->screen, 60, position);
  bunny_delete_clipable(&position->pix->clipable);
  bunny_stop(position->screen);
  bunny_delete_ini(position->file);
  /*free_all(pos, color);*/
  return (0);
}
