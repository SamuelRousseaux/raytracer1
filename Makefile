##
## Makefile for Makefile in /home/samuel/MUL/bsraytracer1
## 
## Made by Samuel
## Login   <samuel.rousseaux@epitech.eu>
## 
## Started on  Mon Feb 13 13:40:44 2017 Samuel
## Last update Wed Mar 15 17:29:12 2017 Samuel Rousseaux
##

SRCS=	./src/calc_dir_vector.c		\
	./src/cylinder.c		\
	./src/light.c			\
	./src/main.c 			\
	./src/my_framebuffer_create.c	\
	./src/my_framebuffer_destroy.c	\
	./src/my_put_pixel.c		\
	./src/plane.c			\
	./src/raytrace_scene.c		\
	./src/sphere.c			\
	./src/vector.c			\

OBJS=	$(SRCS:.c=.o)

NAME= 	raytracer1

CC=	gcc

CFLAGS=	-W -Werror -Wall -I./inc

RM=	rm -f

LIB=	-lm -lc_graph_prog

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
