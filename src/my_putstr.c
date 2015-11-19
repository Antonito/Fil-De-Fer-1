/*
** my_putstr.c for Piscine_C_J04 in /home/bache_a/rendu/Piscine_C_J04
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Thu Oct  1 11:06:31 2015 Antoine Baché
** Last update Wed Nov 18 21:00:46 2015 Antoine Baché
*/

#include "../include/my.h"

void	my_putstr_err(char *str)
{
  while (*str)
    {
      my_putchar_err(*str);
      str++;
    }
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}
