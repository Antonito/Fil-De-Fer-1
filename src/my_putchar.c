/*
** my_putchar.c for my_putchar in /home/bache_a/rendu
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Sep 30 10:08:48 2015 Antoine Baché
** Last update Wed Nov 18 20:52:06 2015 Antoine Baché
*/

#include <unistd.h>

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
