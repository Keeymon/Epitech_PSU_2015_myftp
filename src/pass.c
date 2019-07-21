/*
** pass.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu May 12 18:35:53 2016 Yann Pichereau
** Last update Thu May 12 18:38:15 2016 Yann Pichereau
*/

#include "myftp.h"

void	pass(t_server *server)
{
  if (strcmp(server->cmd, DEFAULT_PASS) == 0)
    server->client->pass = 1;
  else
    printf("Fail Pass\n");
}
