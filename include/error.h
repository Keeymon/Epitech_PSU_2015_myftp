/*
** error.h for  in /home/picher_y/rendu/PSU_2015_myftp/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 17:49:30 2016 Yann Pichereau
** Last update Wed May  4 17:00:36 2016 Yann Pichereau
*/

#ifndef ERROR_H_
# define ERROR_H_

# define FAILURE -1
# define SUCCESS 0

# define ERR_SOCKET "Error: Socket"
# define ERR_BIND "Error: Bind"
# define ERR_LISTEN "Error: Listen"
# define ERR_ACCEPT "Error: Accept"

# define ERR_FORMAT "Error Usage: ./server <port> <path>"
# define ERR_MALLOC "Error: Malloc"

int	error_handler(char *err);
int	perror_handler(char *err);

#endif /* !ERROR_H_ */
