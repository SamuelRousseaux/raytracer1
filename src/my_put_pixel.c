/*
** my_put_pixel.c for my_put_pixel in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 16:28:37 2017 Samuel
** Last update Sun Mar 19 22:26:54 2017 Samuel
*/

#include "framebuffer.h"

int	my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color)
{
  if ((x < 0) || (y < 0) || (x > FRAMEBUFFER_WIDTH - 1) ||
      (y > FRAMEBUFFER_HEIGHT - 1))
    return (0);
  framebuffer->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4] = color.r;
  framebuffer->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 3] = color.a;
  return (0);
}
