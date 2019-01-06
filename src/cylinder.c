/*
** cylinder.c for cylinder in /home/samuel.rousseaux/raytracer1
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Fri Mar  3 18:31:15 2017 Samuel Rousseaux
** Last update Mon Mar 20 15:39:33 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = 0;
  return (normal_vec);
}

float	sqb(float nb)
{
  nb = nb * nb;
  return (nb);
}

float		calc_kcyl(float a, float b, float d)
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

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius)
{
  float	a;
  float	b;
  float	c;
  float	d;

  a = sqb(dir_vector.x) + sqb(dir_vector.y);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y);
  c = sqb(eye_pos.x) + sqb(eye_pos.y) - sqb(radius);
  d = sqb(b) - (4 * a * c);
  if (d > 0)
    return (calc_kcyl(a, b, d));
  else if (d == 0)
    return (-((b) / (2 * a)));
  else
    return (-1.0f);
}
