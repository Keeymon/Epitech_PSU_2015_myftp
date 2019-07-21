/*
** user.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon May  9 17:54:20 2016 Yann Pichereau
** Last update Thu May 12 18:32:50 2016 Yann Pichereau
*/

#include "myftp.h"

void	user(t_server *server)
{
  if (strcmp(server->cmd, DEFAULT_ACCOUNT) == 0)
    server->client->login = 1;
  else
    printf("Fail Login\n");
}
