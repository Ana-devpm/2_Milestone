# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 15:48:43 by afailde-          #+#    #+#              #
#    Updated: 2025/01/21 19:52:41 by afailde-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador y banderas
CC				=	cc
FLAGS			=	-Wextra -Werror -Wall -g3 -fsanitize=address
RM				=	rm -f

# Ejecutables
NAME_SERVER     =	server
NAME_CLIENT		=	client

# Fuentes y objetos del servidor, cliente y utils
SERVER_SRC      =	server.c
CLIENT_SRC      =	client.c
LIBFT			=	libft/libft.a
SERVER_OBJ      =	server.o
CLIENT_OBJ      =	client.o

# Objetivo principal
all: $(NAME_SERVER) $(NAME_CLIENT)

# Compilar el servidor
$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT) 
	@echo "Compilando $(NAME_SERVER)..."
	$(CC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER) creado."

# Compilar el cliente
$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "Compilando $(NAME_CLIENT)..."
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT) creado."

$(LIBFT):
	make -sC libft
# Regla genérica para compilar archivos .c en .o
%.o: %.c
	@echo "Compilando $< en $@..."
	$(CC) $(FLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	make -sC libft fclean
	@echo "Limpiando proyecto principal..."
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

# Limpieza completa
fclean: clean
	@echo "Eliminando ejecutables..."
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Reconstruir todo
re: fclean all

# Declarar objetivos que no son archivos
.PHONY: all clean fclean re
