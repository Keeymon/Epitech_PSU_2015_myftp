/*
** cmd.h for  in /home/picher_y/rendu/PSU_2015_myftp/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon May  9 15:54:10 2016 Yann Pichereau
** Last update Thu May 12 18:59:28 2016 Yann Pichereau
*/

#ifndef CMD_H_
# define CMD_H_

# include <stdlib.h>
# include "myftp.h"

typedef struct	s_cmd
{
  char		*cmd;
  void		(*func)(t_server *server);
}		t_cmd;

static t_cmd	g_cmd[] =
  {
    {"USER ", &user},
    {"PASS", &pass},
    {"CWD ", &cwd},
    {"CDUP", &cdup},
    {"QUIT", &quit},
    {"DELE ", &dele},
    {"PWD", &pwd},
    {"PASV", &pasv},
    {"PORT ", &port},
    {"HELP ", &help},
    {"NOOP", &noop},
    {"RETR ", &retr},
    {"STOR ", &stor},
    {"LIST ", &list},
    {NULL}
  };

#endif /* !CMD_H_ */
