/*
** my_framebuffer_create.c for my_framebuffer_create in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 16:01:15 2017 Samuel
** Last update Wed Mar 15 18:04:51 2017 Samuel
*/

#include "framebuffer.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*framebuffer;

  if ((framebuffer = malloc(sizeof(t_my_framebuffer) + 1)) == NULL)
    return (NULL);
  if ((framebuffer->pixels = malloc(sizeof(sfUint8) *
				    width * height * 4)) == NULL)
    return (NULL);
  i = 0;
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}
