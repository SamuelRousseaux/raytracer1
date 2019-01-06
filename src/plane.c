/*
** plane.c for plane in /home/samuel/MUL/raytracer1/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Feb 15 14:35:49 2017 Samuel
** Last update Sun Mar 19 22:27:25 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	normal_vec;

  normal_vec.x = 0;
  normal_vec.y = 0;
  normal_vec.z = upward;
  return (normal_vec);
}

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  k = (-eye_pos.z) / (dir_vector.z);
  if (k > 0)
    return (k);
  else
    return (-1.0f);
}
