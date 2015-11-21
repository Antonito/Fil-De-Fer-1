/*
** my_strcmp.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 20:56:26 2015 Antoine Baché
** Last update Sat Nov 21 19:19:31 2015 Antoine Baché
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (*str)
    {
      ++str;
      ++i;
    }
  return (i);
}

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;
  int	diff;
  int	j;

  i = 0;
  diff = 0;
  j = my_strlen(s1);
  if (j < my_strlen(s2))
    j = my_strlen(s2);
  while (i < j + 1)
    {
      if (s1[i] != s2[i])
	diff = s1[i] - s2[i];
      ++i;
    }
  return (diff);
}
