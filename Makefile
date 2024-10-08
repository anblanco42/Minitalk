# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anblanco <anblanco@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 14:18:56 by anblanco          #+#    #+#              #
#    Updated: 2024/08/14 14:55:30 by anblanco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC = ./src/
DIR_LIBFT = ./libft/
LIBFT_BIN = $(DIR_LIBFT)libft.a

SRC = client.c\
		server.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

CLEAN = rm -Rf

all:	$(LIBFT_BIN) server client

$(LIBFT_BIN):
	make --directory=$(DIR_LIBFT)

server: $(DIR_SRC)server.c
		$(CC) $(CFLAGS) src/server.c -o server -I$(DIR_LIBFT) -L$(DIR_LIBFT) -lft

client: $(DIR_SRC)client.c
		$(CC) $(CFLAGS) src/client.c -o client -I$(DIR_LIBFT) -L$(DIR_LIBFT) -lft

$(NAME): $(OBJS) $(LIBFT_BIN)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_BIN) -o $(NAME)

clean: 
		@echo --------------------------------------------------------------------------------
		@echo
		@echo "                          ---Deleting objects :) ---                          "
		$(CLEAN) server
		$(CLEAN) client
		@echo
		@echo --------------------------------------------------------------------------------
	make clean --directory=$(DIR_LIBFT)
fclean: clean
	$(CLEAN) $(NAME)
	make fclean --directory=$(DIR_LIBFT)

re: fclean all 
.PHONY: all clean fclean