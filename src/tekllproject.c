/*
** tekllproject.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 11:30:15 2015 Antoine Baché
** Last update Fri Nov 20 01:59:37 2015 Antoine Baché
*/

#include "../include/my.h"

void	tekllproject(t_bunny_position *out, int x, int y, int z)
{
  out->x = x + y;
  out->y = -(z + y);
}
