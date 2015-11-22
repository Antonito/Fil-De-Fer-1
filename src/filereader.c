/*
** filereader.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 14:50:25 2015 Antoine Baché
** Last update Sun Nov 22 17:24:15 2015 Antoine Baché
*/

#include "../include/my.h"

int	get_ground(t_position *position)
{
  int	i;

  i = 0;
  if (position->width == 0 || position->height == 0)
    return (1);
  else if ((position->posg = bunny_malloc(sizeof(t_bunny_position) *
				   ((position->width *
				     position->height)))) == NULL)
    return (1);
  while (i < position->width * position->height)
    {
      tekllproject(&position->posg[i], i % position->width,
		   i / position->height, 0);
      ++i;
    }
  return (0);
}

int	filereader(t_position *position, t_bunny_ini *file)
{
  int	i;
  int	z;

  i = 0;
  position->width =
    my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  position->height =
    my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  if (position->width == 0 || position->height == 0)
    return (1);
  else if ((position->pos = bunny_malloc(sizeof(t_bunny_position) *
				   ((position->width *
				     position->height)))) == NULL)
    return (1);
  while (i < position->width * position->height)
    {
      z =
	my_getnbr((char *)bunny_ini_get_field(file, "forme1", "data", i));
      tekllproject(&position->pos[i], i % position->width,
		   i / position->height, z);
      ++i;
    }
  return (0);
}

int	check_file(t_position *position, t_bunny_ini *file)
{
  if (bunny_ini_get_field(file, "forme1", "width", 0) == NULL)
    {
      my_putstr_err("Incorrect name, must be [forme1]\n");
      return (1);
    }
  else if (my_strcmp(bunny_ini_get_field(file, "forme1", "type", 0), "fdf1")
	   != 0)
    {
      my_putstr_err("Incorrect type, must be fdf1\n");
      return (1);
    }
  else if (filereader(position, file) == 1)
    return (1);
  else if (get_ground(position) == 1)
    return (1);
  position->stepx = SIZE_X / (2 * position->width);
  position->stepy = ((position->height <= 2) ? (SIZE_Y / 4) : position->stepx);
  return (0);
}
