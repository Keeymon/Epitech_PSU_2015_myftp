##
## Makefile for  in /home/picher_y/rendu/PSU_2015_myftp/client
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Mon May  9 12:59:04 2016 Yann Pichereau
## Last update Mon May  9 13:41:40 2016 Yann Pichereau
##

NAME =		client

CC =		gcc

RM =		rm -f

CP =		cp

CFLAGS +=	-W -Wall -Werror -Wall

SRCS =		client.c	\

OBJS =		$(SRCS:.c=.o)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean :
		$(RM) $(OBJS)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
