/*
** my.h for fdf1 in /home/bache_a/Infographie/gfx_fdf1/include
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 13:48:55 2015 Antoine Baché
** Last update Thu Nov 19 13:51:10 2015 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_

# include <lapin.h>

void			prepare_my_pos(t_bunny_position *pos, int i);
int			my_strlen(const char *str);
void			my_putchar_err(char c);
void			my_putchar(char c);
void			my_putstr(char *str);
void			my_putstr_err(char *str);
int			my_setline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
int			my_strcmp(char *s1, char *s2);
void			tekllproject(t_bunny_position *out, int x, int y, int z);
void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
void			tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
void			my_square(t_bunny_pixelarray *pix, t_color *color);
void			my_setpos(t_bunny_position *tmp, t_bunny_position *pos, int i);
t_bunny_position	*filereader(t_bunny_position *pos);

#endif /* !MY_H_ */
