/*
** client.c for  in /home/picher_y/rendu/PSU_2015_myftp
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed May  4 19:10:55 2016 Yann Pichereau
** Last update Mon May  9 13:42:43 2016 Yann Pichereau
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int			main(int ac, char **av)
{
  struct sockaddr_in	addr;
  int			id;

  char buf[128];
  int ret;

  if (ac != 2)
    return (1);
  if ((id = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (1);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = atoi(av[1]);
  if (connect(id, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    return (1);
  printf("Connected Server\n");
  usleep(1000);
  ret = read(id, buf, 128);
  buf[ret] = '\0';
  printf(buf);
  return (0);
}
