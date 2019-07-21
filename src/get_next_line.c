/*
** get_next_line.c for  in /home/picher_y/rendu/CPE_2015_get_next_line
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Nov 24 10:32:29 2015 Yann Pichereau
** Last update Mon May  9 14:27:07 2016 Yann Pichereau
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	my_memcat(t_line *line, char *ret, char *str, int ptr)
{
  int	i;

  i = 0;
  while (i < line->nb)
    {
      str[i] = ret[i];
      i++;
    }
  free(ret);
  line->nb += line->index - ptr;
  while (i < line->nb)
    {
      str[i] = line->buff[ptr];
      ptr++;
      i++;
    }
}

char	*my_realloc(t_line *line, char *ret)
{
  int	ptr;
  char	*str;

  ptr = line->index;
  while (line->buff[line->index] != '\n' && line->index < line->len)
    line->index++;
  if ((str = malloc(sizeof(char) * (line->nb + line->index - ptr + 1))) == NULL)
    return (NULL);
  str[line->nb + line->index - ptr] = '\0';
  my_memcat(line, ret, str, ptr);
  if (line->buff[line->index] == '\n' || line->len < READ_SIZE)
    {
      line->end = 1;
      line->nb = 0;
      line->index++;
    }
  if (line->index >= line->len || line->len == 0)
    line->index = 0;
  return (str);
}

char		*get_next_line(const int fd)
{
  static t_line	line = {{}, 0, 0, 0, 0};
  char		*ret;

  if ((ret = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  ret[0] = '\0';
  line.end = 0;
  if (line.index != 0 && (ret = my_realloc(&line, ret)) == NULL)
    return (NULL);
  while (line.end == 0)
    {
      if ((line.len = read(fd, line.buff, READ_SIZE)) < 0 ||
	  (line.len == 0 && line.nb == 0))
	{
	  free(ret);
	  return (NULL);
	}
      line.buff[line.len] = '\0';
      if ((ret = my_realloc(&line, ret)) == NULL)
	return (NULL);
    }
  return (ret);
}
