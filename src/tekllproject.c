/*
** tekllproject.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 11:30:15 2015 Antoine Baché
** Last update Sun Nov 22 04:40:17 2015 Antoine Baché
*/

#include "../include/my.h"

void	tekllproject(t_bunny_position *out, int x, int y, int z)
{
  out->x = (x / 2 + y);
  out->y = -z + y;
}
