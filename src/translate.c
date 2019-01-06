/*
** translate.c for translate in /home/samuel/MUL/raytracer1/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Mar 15 17:47:30 2017 Samuel
** Last update Wed Mar 15 17:52:07 2017 Samuel
*/

#include "framebuffer.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
