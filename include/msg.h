/*
** msg.h for  in /home/picher_y/rendu/PSU_2015_myftp/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon May  9 17:16:41 2016 Yann Pichereau
** Last update Mon May  9 17:17:19 2016 Yann Pichereau
*/

#ifndef MSG_H_
# define MSG_H_

# define MSG_READY "220 Service ready for new user.\n"
# define MSG_USER "230 User logged in, proceed.\n"
# define MSG_USER_OK "331 User name okay, need password.\n"
# define MSG_PASS MSG_USER
# define MSG_PASS_OK "332 Need account for login.\n"
# define MSG_ACTION_OK "250 Requested file action okay, completed.\n"
# define MSG_CREATE_FILE "257 %s created.\n"
# define MSG_CMD_OK "200 Command okay.\n"
# define MSG_STATUS_OK "150 File status okay.\n"

#endif /* !MSG_H_ */
