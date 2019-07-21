/*
** send.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 19:06:24 2016 Yann Pichereau
** Last update Thu May 12 18:34:55 2016 Yann Pichereau
*/

#include <string.h>
#include <unistd.h>
#include "myftp.h"

int	send_from_server(t_server *server, char *msg)
{

  int	ret;

  ret = write(server->client->id_socket, msg, strlen(msg));
  printf("(%d) (%s) Write de %d\n", server->client->id_socket, msg, ret);
  return (SUCCESS);
}
