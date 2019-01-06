/*
** sphere.c for sphere in /home/samuel/MUL/raytracer1/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Feb 15 14:31:01 2017 Samuel
** Last update Sun Mar 19 22:29:25 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	intersection_point(sfVector3f dir_vector, sfVector3f eye_pos,
				   float dist, float radius)
{
  sfVector3f	int_pt;

  radius = radius;
  int_pt.x = (eye_pos.x + dist * dir_vector.x) / (radius * 200);
  int_pt.y = (dir_vector.y * dist + eye_pos.y) / (radius * 200);
  int_pt.z = (dir_vector.z * dist + eye_pos.z) / (radius * 200);
  return (int_pt);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = intersection_point.z;
  return (normal_vec);
}

float	sqa(float nb)
{
  nb = nb * nb;
  return (nb);
}

float		calc_k(float a, float b, float d)
{
  float	k1;
  float	k2;

  k1 = -((b) + sqrt(d)) / (2 * a);
  k2 = -((b) - sqrt(d)) / (2 * a);
  if (k1 <= 0 && k2 <= 0)
    return (-1.0f);
  if ((k1 > 0 && k1 < k2) || (k1 > 0 && k2 <= 0))
    return (k1);
  if ((k2 > 0 && k2 < k1) || (k2 > 0 && k1 <= 0))
    return (k2);
  else
    return (-1.0f);
}

float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
				 float radius)
{
  float	a;
  float	b;
  float	c;
  float	d;

  a = sqa(dir_vector.x) + sqa(dir_vector.y) + sqa(dir_vector.z);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y +
	   eye_pos.z * dir_vector.z);
  c = sqa(eye_pos.x) + sqa(eye_pos.y) + sqa(eye_pos.z) - sqa(radius);
  d = sqa(b) - (4 * a * c);
  if (d > 0)
    return (calc_k(a, b, d));
  else if (d == 0)
    return (-((b) / (2 * a)));
  else
    return (-1.0f);
}
