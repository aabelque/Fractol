# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabelque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 11:58:57 by aabelque          #+#    #+#              #
#    Updated: 2018/05/24 16:39:58 by aabelque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS = -framework OpenGL -framework AppKit

NAME = fractol

CC = gcc

CFLAG = -Wall -Werror -Wextra -g

MAKE = make

SRC = srcs/main.c \
	  srcs/error.c \
	  srcs/init_mlx.c \
	  srcs/parsing.c \
	  srcs/mandelbrot.c \
	  srcs/mandelbrot2.c \
	  srcs/clean.c \
	  srcs/init_env.c \
	  srcs/map_control.c \
	  srcs/draw.c \
	  srcs/julia.c \
	  srcs/burningship.c \
	  srcs/colors.c \
	  srcs/key_hook.c \
	  srcs/mouse_hook.c \
	  srcs/move.c

OBJS = $(SRC:%.c=%.o)
	INCDIR = include/
	INCFILE = fractol.h
	INC = $(addprefix $(INCDIR), $(INCFILE))

LIBPATH = libs/

LFTDIR = libft/
LFTPATH = $(addprefix $(LIBPATH), $(LFTDIR))
LIBFT = libft.a
FTLK = ft

LMLXDIR = minilibx/
LMLXPATH = $(addprefix $(LIBPATH), $(LMLXDIR))
LIBMLX = libmlx.a
MLXLK = mlx

ALLINCS = -I$(LFTPATH) -I$(LMLXPATH) -I$(INCDIR)

ifneq ($(NOERR),yes)
	CFLAG -= -Werror
endif

ifeq ($(SAN),yes)
	CFLAG += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

all: $(NAME)

$(NAME): $(LFTPATH)$(LIBFT) $(LMLXPATH)$(LIBMLX) $(OBJS) $(INC) 
	@$(CC) $(CFLAG) -O3 -o $(NAME) $(ALLINCS) -L$(LFTPATH) -l$(FTLK) -L$(LMLXPATH) -l$(MLXLK) $(FRAMEWORKS) $(OBJS)
	-@echo "\033[32m[ ✔ ] Fractol ready.\033[0m"

%.o: %.c $(INC)
	@$(CC) $(CFLAG) -o $@ $(ALLINCS) -c $<

$(LFTPATH)$(LIBFT):
	$(MAKE) -C $(LFTPATH) NOERR=$(NOERR) SAN=$(SAN)

$(LMLXPATH)$(LIBMLX):
	$(MAKE) -C $(LMLXPATH)

clean:
	$(MAKE) -C $(LFTPATH) clean
	@rm -rf $(INCDIR)/*.h.gch
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	$(MAKE) -C $(LMLXPATH) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
