/*
** recv.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 19:06:43 2016 Yann Pichereau
** Last update Thu May 12 18:35:11 2016 Yann Pichereau
*/

#include <string.h>
#include "myftp.h"

int	recv_from_server(t_server *server)
{
  if ((server->cmd = get_next_line(server->client->id_socket)) == NULL)
    return (FAILURE);
  printf("CMD RECV = %s\n", server->cmd);
  return (SUCCESS);
}
