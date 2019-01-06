/*
** light.c for light in /home/samuel/MUL/raytracer1/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Thu Feb 16 13:33:45 2017 Samuel
** Last update Sun Mar 19 22:24:36 2017 Samuel
*/

#include "framebuffer.h"

float	get_light_coef(sfVector3f light_vector,
		       sfVector3f normal_vector)
{
  float	light_coef;

  light_coef = normal_vector.x * light_vector.x +
    normal_vector.y * light_vector.y +
    normal_vector.z * light_vector.z;
  if (light_coef < 0)
    light_coef = 0;
  return (light_coef);
}
