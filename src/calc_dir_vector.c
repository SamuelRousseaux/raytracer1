/*
** raytrace.c for raytrace in /home/samuel/MUL/bsraytracer1/srcs
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 13 13:44:19 2017 Samuel
** Last update Wed Mar 15 17:52:18 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
