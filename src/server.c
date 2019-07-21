/*
** server.c for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed May  4 15:09:58 2016 Yann Pichereau
** Last update Thu May 12 19:01:24 2016 Yann Pichereau
*/

#include <unistd.h>
#include <stdlib.h>
#include "cmd.h"
#include "msg.h"
#include "myftp.h"

int	connect_client(t_server *server)
{
  send_from_server(server, PROMPT_R);
  return (SUCCESS);
}

int	trim_cmd(t_server *server)
{
  int	i;
  char	*str;

  i = -1;
  while (server->cmd[++i] != ' ' && server->cmd[i] != '\0');
  if (strlen(server->cmd) - 1 > (size_t)i)
    {
      i++;
      if ((str = malloc(strlen(server->cmd) - i + 1)) == NULL)
	return (error_handler(ERR_MALLOC));
      memcpy(str, &server->cmd[i], strlen(server->cmd) - i);
      str[strlen(server->cmd) - i] = '\0';
      free(server->cmd);
      server->cmd = str;
    }
  else
    {
      free(server->cmd);
      server->cmd = NULL;
    }
  return (SUCCESS);
}

int	search_cmd(t_server *server)
{
  int	i;

  i = -1;
  while (g_cmd[++i].cmd != NULL)
    {
      if (strncmp(g_cmd[i].cmd, server->cmd, strlen(g_cmd[i].cmd)) == 0)
	{
	  trim_cmd(server);
	  if (server->cmd != NULL)
	    printf("CMD OK %s\n", server->cmd);
	  g_cmd[i].func(server);
	  return (SUCCESS);
	}
    }
  return (FAILURE);
}

int	proc_loop(t_server *server, t_client *client)
{
  printf("Connected Client : Port = %d | Path = %s | fd = %d\n", server->addr.sin_port, server->path,
	 client->id_socket);
  client->login = 0;
  client->pass = 0;
  server->client = client;
  send_from_server(server, MSG_READY);
  connect_client(server);
  while (1)
    {
      if (recv_from_server(server) == SUCCESS)
	{
	  if (search_cmd(server) != SUCCESS)
	    printf("BAD CMD\n");
	}
    }
  return (1);
}

int	init_server(t_server *server)
{
  if ((server->id_socket = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (perror_handler(ERR_SOCKET));
  server->addr.sin_family = AF_INET;
  server->addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server->addr.sin_port = htons(USER_PORT(server));
  if (bind(server->id_socket, (struct sockaddr*)&server->addr,
	   sizeof(server->addr)) != 0)
    return (perror_handler(ERR_BIND));
  if (listen(server->id_socket, MAX_CONNECT) != 0)
    return (perror_handler(ERR_LISTEN));
  return (SUCCESS);
}

int	accept_client(t_server *server)
{
  t_client	*client;

  if ((client = malloc(sizeof(t_client))) == NULL)
    return (error_handler(ERR_MALLOC));
  if ((client->id_socket = accept(server->id_socket, NULL, NULL)) < 0)
    return (perror_handler(ERR_ACCEPT));
  if ((client->pid = fork()) == 0)
    return (proc_loop(server, client));
  return (SUCCESS);
}
