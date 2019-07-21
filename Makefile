##
## Makefile for  in /home/picher_y/rendu/PSU_2015_myftp
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Tue May  3 16:35:59 2016 Yann Pichereau
## Last update Thu May 12 18:52:14 2016 Yann Pichereau
##

NAME =		server

CC =		gcc

CP =		cp

RM =		rm -f

INCLUDE =	

CFLAGS +=	-W -Wall -Wextra -Werror -I./include

SRCS =		src/main.c		\
		src/error.c		\
		src/send.c		\
		src/recv.c		\
		src/server.c		\
		src/get_next_line.c	\
		src/user.c		\
		src/pass.c		\
		src/help.c		\
		src/pasv.c		\
		src/list.c		\
		src/dele.c		\
		src/quit.c		\
		src/retr.c		\
		src/stor.c		\
		src/pwd.c		\
		src/cwd.c		\
		src/cdup.c		\
		src/port.c		\
		src/noop.c		\

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(INCLUDE) $(CFLAGS)

clean :
		$(RM) $(OBJS)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
