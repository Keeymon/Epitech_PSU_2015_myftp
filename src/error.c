/*
** error.h for  in /home/picher_y/rendu/PSU_2015_myftp/src
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue May  3 16:46:31 2016 Yann Pichereau
** Last update Tue May  3 17:55:58 2016 Yann Pichereau
*/

#include <stdio.h>
#include "error.h"

int	error_handler(char *err)
{
  fprintf(stderr, "Server %s\n", err);
  return (FAILURE);
}

int	perror_handler(char *err)
{
  perror(err);
  return (FAILURE);
}
