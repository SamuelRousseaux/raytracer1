/*
** framebuffer.h for framebuffer.h in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 15:55:19 2017 Samuel
** Last update Sun Mar 19 22:36:57 2017 Samuel
*/

#ifndef FRAMEBUFFER_H_
# define FUNCTION_H_

# include <stdlib.h>
# include <SFML/Graphics.h>
# include <math.h>
# include <stdio.h>

# define FRAMEBUFFER_WIDTH 600
# define FRAMEBUFFER_HEIGHT 400

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

float			get_light_coef(sfVector3f, sfVector3f);
sfVector3f		get_normal_sphere(sfVector3f);
sfVector3f		get_normal_plane(int);
float			intersect_cylinder(sfVector3f, sfVector3f, float);
float			intersect_sphere(sfVector3f, sfVector3f, float);
float			intersect_plane(sfVector3f, sfVector3f);
sfVector3f		intersection_point(sfVector3f, sfVector3f,
					   float, float);
t_my_framebuffer	*my_framebuffer_create(int, int);
void			my_framebuffer_destroy(t_my_framebuffer *);
int			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			process_game_loop(sfRenderWindow *, sfSprite *,
					  sfTexture *);
sfVector2i		put_vec2i(int, int);
sfVector3f		put_vec3f(float, float, float);
sfVector3f		calc_dir_vector(float, sfVector2i, sfVector2i);
void			raytrace_scene(t_my_framebuffer *, sfVector3f);
float			sqr(float);

#endif /* !FRAMEBUFFER_H_ */
