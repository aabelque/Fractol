# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabelque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:03:18 by aabelque          #+#    #+#              #
#    Updated: 2018/05/19 15:04:37 by aabelque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_factorial.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	  ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_strjoin2.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_strcat.c \
	  ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	  ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	  ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_swap.c ft_tolower.c ft_toupper.c get_msg.c ft_add_endlist.c \
	  ft_nb_elemlist.c  ft_pushback_list.c ft_add_list.c epur_str.c \
	  ft_rm_endlist.c ft_rm_frontlist.c ft_rmlist.c get_next_line.c \
	  ft_itoa_base.c ft_atoi_base.c

HEADERS = -Ilibft.h

OBJ = $(SRC:%.c=%.o)

all: print $(NAME)

print:
	@echo "\033[32m[\c"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m[ ✔ ] Built library]\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo "\033[33m✔ \c"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32m[ ✔ ] Cleaned up object files.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32m[ ✔ ] Cleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
