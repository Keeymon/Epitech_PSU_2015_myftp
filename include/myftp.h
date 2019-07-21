/*
** myftp.h for  in /home/picher_y/rendu/PSU_2015_myftp/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 16:42:09 2016 Yann Pichereau
** Last update Thu May 12 19:00:16 2016 Yann Pichereau
*/

#ifndef MYFTP_H_
# define MYFTP_H_

# include <stdio.h>
# include <string.h>

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include "error.h"
# include "get_next_line.h"

# define MAX_CONNECT 100

# define DEFAULT_PORT 25
# define USER_PORT(s) (s->addr.sin_port)
# define PORT USER_PORT

# define DEFAULT_IP "127.0.0.0"

# define DEFAULT_ACCOUNT "Anonymous"
# define DEFAULT_PASS ""

# define PROMPT_L " <- "
# define PROMPT_R " -> "

typedef struct	s_client
{
  pid_t		pid;
  int		id_socket;
  int		login;
  int		pass;
}		t_client;

typedef struct		s_server
{
  char			*path;
  int			id_socket;
  struct sockaddr_in	addr;
  t_client		*client;
  char			*cmd;
}			t_server;

int	init_server(t_server *server);
int	accept_client(t_server *server);
int	send_from_server(t_server *server, char *msg);
int	recv_from_server(t_server *server);
void	user(t_server *server);
void	pass(t_server *server);
void	noop(t_server *server);
void	help(t_server *server);
void	pwd(t_server *server);
void	cwd(t_server *server);
void	cdup(t_server *server);
void	pasv(t_server *server);
void	port(t_server *server);
void	retr(t_server *server);
void	dele(t_server *server);
void	quit(t_server *server);
void	list(t_server *server);
void	stor(t_server *server);

#endif /* !MYFTP_H_ */
