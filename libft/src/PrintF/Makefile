# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 20:26:59 by anblanco          #+#    #+#              #
#    Updated: 2023/11/20 18:39:35 by anblanco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_formato.c ft_paint.c ft_paint_hexa.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc -c

AR = ar

CLEAN = rm -Rf

OBJS := $(SRC:.c=.o)

all:		$(NAME)

$(OBJS): %.o: %.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
			$(AR) -rcs $(NAME) $(OBJS)

clean: 
	@$(CLEAN) ./*.o

fclean: clean
	@$(CLEAN) ./*.a

re: fclean all 
.PHONY: all clean fclean