/*
** cone.c for cone in /home/samuel/MUL/raytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Tue Mar  7 15:11:44 2017 Samuel
** Last update Sun Mar 19 22:25:16 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = intersection_point.z * -tan(semiangle);
  return (normal_vec);
}

float	sqc(float nb)
{
  nb = nb * nb;
  return (nb);
}

float		calc_kcone(float a, float b, float d)
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

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  float	a;
  float	b;
  float	c;
  float	d;
  float	k1;
  float	k2;

  k1 = -1.0f;
  a = sqc(dir_vector.x) + sqc(dir_vector.y) -
    (sqc(dir_vector.z) * sqc(tan(semiangle)));
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y) -
	   (eye_pos.z * dir_vector.z * sqc(tan(semiangle))));
  c = sqc(eye_pos.x) + sqc(eye_pos.y) - (sqc(eye_pos.z) * sqc(tan(semiangle)));
  d = sqc(b) - (4 * a * c);
  if (d > 0)
    return (calc_kcone(a, b, d));
  else if (d == 0)
    return (-((b) / (2 * a)));
  else
    return (-1.0f);
}
