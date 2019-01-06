/*
** vector.c for vector in /home/samuel/MUL/bsraytracer1/srcs
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 13 13:47:42 2017 Samuel
** Last update Wed Mar 15 17:55:08 2017 Samuel
*/

#include "framebuffer.h"

sfVector2i	put_vec2i(int x, int y)
{
  sfVector2i	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfVector3f	put_vec3f(float x, float y, float z)
{
  sfVector3f	vec;

  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}
