/*
** main.c for main test raytracer in /home/samuel/MUL/bsraytracer1
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 10 14:49:22 2017 Samuel
** Last update Sun Mar 19 22:26:05 2017 Samuel
*/

#include "framebuffer.h"

int			main()
{
  sfVideoMode		mode = {FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 32};
  sfRenderWindow*	window;
  sfTexture*		texture;
  sfSprite*		sprite;

  window = sfRenderWindow_create(mode, "Ugly Raytracer 1",
				 sfResize | sfClose, NULL);
  if (!window)
    return EXIT_FAILURE;
  texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  if (!texture)
    return EXIT_FAILURE;
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  process_game_loop(window, sprite, texture);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return EXIT_SUCCESS;
}

sfVector3f	update_eye(sfVector3f eye_pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    eye_pos.x -= 1;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    eye_pos.x += 1;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    eye_pos.y -= 1;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    eye_pos.y += 1;
  if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue)
    eye_pos.z -= 1;
  if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
    eye_pos.z += 1;
  return (eye_pos);
}

sfVector3f	init_eye()
{
  sfVector3f	eye_pos;

  eye_pos.x = -200;
  eye_pos.y = 0;
  eye_pos.z = 0;
  return (eye_pos);
}

void			process_game_loop(sfRenderWindow *window,
					  sfSprite *sprite,
					  sfTexture *texture)
{
  sfEvent		event;
  t_my_framebuffer	*framebuffer;
  sfVector3f		eye_pos;

  eye_pos = init_eye();
  while (sfRenderWindow_isOpen(window))
    {
      framebuffer = my_framebuffer_create(FRAMEBUFFER_WIDTH,
					  FRAMEBUFFER_HEIGHT);
      raytrace_scene(framebuffer, eye_pos);
      eye_pos = update_eye(eye_pos);
      sfTexture_updateFromPixels(texture, framebuffer->pixels,
				 framebuffer->width, framebuffer->height, 0, 0);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      my_framebuffer_destroy(framebuffer);
    }
}
