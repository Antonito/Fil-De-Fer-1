/*
** my_escape.c for fdf1 in /home/bache_a/Infographie/gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 14:51:30 2015 Antoine Baché
** Last update Sun Nov 22 05:41:59 2015 Antoine Baché
*/

#include "../include/my.h"

t_bunny_response	my_escape(t_bunny_event_state state,
				  t_bunny_keysym keysym, void *data)
{
  data = data;
  if (state == GO_DOWN && keysym == BKS_ESCAPE) 
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
