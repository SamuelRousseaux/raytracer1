/*
** my_framebuffer_destroy.c for my_framebuffer_destroy in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 16:16:50 2017 Samuel
** Last update Wed Mar 15 17:53:48 2017 Samuel
*/

#include "framebuffer.h"

void	my_framebuffer_destroy(t_my_framebuffer *framebuffer)
{
  free(framebuffer);
}
