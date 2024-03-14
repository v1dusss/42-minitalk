# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 14:38:27 by vsivanat          #+#    #+#              #
#    Updated: 2024/03/14 17:06:13 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = libft/libft.a

SERVER = server
CLIENT = client

BONUS_SERVER = bonus_server
BONUS_CLIENT = bonus_client


SV_SRCS = server.c
SV_OBJS = $(SV_SRCS:.c=.o)

BONUS_SV_SRCS = server_bonus.c
BONUS_SV_OBJS = $(BONUS_SV_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

BONUS_CLIENT_SRCS = client_bonus.c
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C ./libft

$(SERVER): $(SV_OBJS) $(LIBFT) minitalk.h
	$(CC) $(CFLAGS) $(SV_OBJS) -o $(SERVER) -L./libft -lft

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) minitalk.h
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) -L./libft -lft

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_SV_OBJS) $(LIBFT) minitalk.h
	$(CC) $(CFLAGS) $(BONUS_SV_OBJS) -o $(BONUS_SERVER) -L./libft -lft

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJS) $(LIBFT) minitalk.h
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) -o $(BONUS_CLIENT) -L./libft -lft

clean:
	make -C ./libft clean
	$(RM) $(SV_OBJS) $(CLIENT_OBJS) $(BONUS_SV_OBJS) $(BONUS_CLIENT_OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all re clean fclean
