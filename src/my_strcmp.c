/*
** my_strcmp.c for fdf1 in /gfx_fdf1/src
** 
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
** 
** Started on  Wed Nov 18 20:56:26 2015 Antoine Baché
** Last update Wed Nov 18 23:03:57 2015 Antoine Baché
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

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	diff;
  int	j;

  i = 0;
  diff = 0;
  j = my_strlen(s1);
  if (j < my_strlen(s1))
    j = my_strlen(s2);
  while (i < j + 1 && !j)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      ++i;
    }
  return (diff);
}
