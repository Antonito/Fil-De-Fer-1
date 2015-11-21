/*
** filereader.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 14:50:25 2015 Antoine Baché
** Last update Sat Nov 21 14:56:36 2015 Antoine Baché
*/

#include "../include/my.h"

int	get_ground(t_position *position, t_bunny_ini *file)
{
  int	i;

  i = 0;
  position->width =
    my_getnbr((char *)bunny_ini_get_field(file, "forme1", "width", 0));
  position->height =
    my_getnbr((char *)bunny_ini_get_field(file, "forme1", "height", 0));
  if ((position->posg =bunny_malloc(sizeof(t_bunny_position) *
				   ((position->width *
				     position->height)))) == NULL)
    return (1);
  while (i < position->width * position->height)
    {
      tekllproject(&position->posg[i], i%position->width, i/position->height, 0);
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
  if ((position->pos =bunny_malloc(sizeof(t_bunny_position) *
				   ((position->width *
				     position->height)))) == NULL)
    return (1);
  while (i < position->width * position->height)
    {
      z = my_getnbr((char *)bunny_ini_get_field(file, "forme1", "data", i));
      tekllproject(&position->pos[i], i%position->width, i/position->height, z);
      ++i;
    }
  return (0);
}
