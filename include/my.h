/*
** my.h for fdf1 in /home/bache_a/Infographie/gfx_fdf1/include
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Sat Nov 14 13:48:55 2015 Antoine Baché
** Last update Sat Nov 21 18:02:41 2015 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define SIZE_X	1024
# define SIZE_Y	768
# define STEPX	100
# define STEPY	140

# include <lapin.h>

typedef struct		s_position
{
  int			width;
  int			height;
  t_bunny_position	*tmp1;
  t_bunny_position	*tmp2;
  t_bunny_position	*pos;
  t_bunny_position	*posg;
  t_bunny_pixelarray	*pix;
  t_bunny_ini		*file;
  t_bunny_window	*screen;
  t_color		*color;
  t_bunny_key		key;
}			t_position;

t_bunny_response	my_loop(void *);
void			prepare_my_pos(t_bunny_position *, int);
int			my_strlen(const char *);
void			my_putchar_err(char);
void			my_putchar(char);
void			my_putstr(char *);
void			my_putstr_err(char *);
int			my_setline(t_bunny_pixelarray *, t_position *, t_color *);
int			my_strcmp(char *, char *);
void			tekllproject(t_bunny_position *, int x, int y, int z);
void			tekline(t_bunny_pixelarray *,
				t_bunny_position *pos, t_color *);
void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *pos, t_color *);
void			my_square(t_bunny_pixelarray *, t_color *);
void			my_setpos(t_position *, int);
void			my_setposg(t_position *, int);
int			filereader(t_position *, t_bunny_ini *);
int			get_ground(t_position *, t_bunny_ini *);
int			my_getnbr(char *);
void			draw_ground(t_bunny_pixelarray *,
				    t_position *, t_color *, int *);
void			draw_shape(t_bunny_pixelarray *,
				   t_position *, t_color *, int *);
void			draw_vertical(t_bunny_pixelarray *,
			      t_position *, t_color *, int *);
void			set_pos(t_position *, int *);
void			set_posg(t_position *, int *);
void			set_posv(t_position *, int *);
t_bunny_response	my_escape(t_bunny_event_state, t_bunny_keysym, void *);

#endif /* !MY_H_ */
