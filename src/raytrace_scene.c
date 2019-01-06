/*
** raytrace_scene.c for raytrace_scene in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 15:46:05 2017 Samuel
** Last update Sun Mar 19 22:28:30 2017 Samuel
*/

#include "framebuffer.h"

sfColor	colorpt(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

void		put_red(t_my_framebuffer *framebuffer, sfVector2i pos, float ks)
{
  float	coef;

  coef = ((0.25 - ks) * 100 / 0.62) * 255 / 100;
  my_put_pixel(framebuffer, pos.x, pos.y, colorpt(0 + (int)coef, 0, 0, 255));
}

void		put_color(t_my_framebuffer *framebuffer, float ks, float kp,
			  sfVector2i pos, sfVector3f dir_vector)
{
  float	light;
  sfVector3f	int_pt;

  int_pt = intersection_point(dir_vector, put_vec3f(-200, 0, 0), ks, 50);
  if (ks < 0 && kp < 0)
    my_put_pixel(framebuffer, pos.x, pos.y, sfBlack);
  if ((ks > 0 && kp < 0) || (ks < kp && ks > 0))
    {
      light = get_light_coef(dir_vector, get_normal_sphere(int_pt));
      my_put_pixel(framebuffer, pos.x, pos.y, colorpt(255 * light, 0, 0, 255));
    }
  else if ((ks < 0 && kp > 0) || (ks > kp && kp > 0))
    {
      light = 1 - get_light_coef(dir_vector, get_normal_plane(1));
      my_put_pixel(framebuffer, pos.x, pos.y, colorpt(0, 0, 255 * light, 255));
    }
}

void		raytrace_scene(t_my_framebuffer *framebuffer,
			       sfVector3f eye_pos)
{
  int		x;
  int		y;
  float	ksphere;
  float	kplane;
  sfVector3f	dir_vector;

  x = 0;
  y = 0;
  while (x < FRAMEBUFFER_WIDTH)
    {
      y = 0;
      while (y < FRAMEBUFFER_HEIGHT)
	{
	  dir_vector = calc_dir_vector(200, put_vec2i(FRAMEBUFFER_WIDTH,
						      FRAMEBUFFER_HEIGHT),
				       put_vec2i(x, y));
	  ksphere = intersect_sphere(eye_pos, dir_vector, 50);
	  kplane = intersect_plane(eye_pos, dir_vector);
	  put_color(framebuffer, ksphere, kplane, put_vec2i(x, y), dir_vector);
	  y++;
	}
      x++;
    }
}
