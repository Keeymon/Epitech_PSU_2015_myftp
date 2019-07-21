/*
** main.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 16:41:34 2016 Yann Pichereau
** Last update Wed May  4 18:54:43 2016 Yann Pichereau
*/

#include <stdlib.h>
#include "myftp.h"

int	check_arg(int ac, char **av, t_server *server)
{
  if (ac != 3)
    return (error_handler(ERR_FORMAT));
  server->addr.sin_port = atoi(av[1]);
  server->path = av[2];
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  t_server	server;

  if (check_arg(ac, av, &server) != 0)
    return (FAILURE);
  if (init_server(&server) != 0)
    return (FAILURE);
  while (accept_client(&server) == 0);
  return (SUCCESS);
}
