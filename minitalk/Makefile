# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 15:48:43 by afailde-          #+#    #+#              #
#    Updated: 2025/01/20 19:23:47 by afailde-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador y banderas
CC				=	cc
FLAGS			=	-Wextra -Werror -Wall
RM				=	rm -f

# Ejecutables
NAME_SERVER     =	server
NAME_CLIENT		=	client

# Fuentes y objetos del servidor, cliente y utils
SERVER_SRC      =	server.c
CLIENT_SRC      =	client.c
UTILS_SRC       =	utils_libft.c
SERVER_OBJ      =	server.o
CLIENT_OBJ      =	client.o
UTILS_OBJ       =	utils_libft.o

# Carpeta y fuentes de ft_printf
FT_PRINTF_DIR   =	utils/ft_printf
FT_PRINTF_SRC   =	$(wildcard $(FT_PRINTF_DIR)/*.c)
FT_PRINTF_OBJ   =	$(FT_PRINTF_SRC:.c=.o)

# Objetivo principal
all: $(NAME_SERVER) $(NAME_CLIENT)

# Compilar el servidor
$(NAME_SERVER): $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ)
	@echo "Compilando $(NAME_SERVER)..."
	$(CC) $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER) creado."

# Compilar el cliente
$(NAME_CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ)
	@echo "Compilando $(NAME_CLIENT)..."
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT) creado."

# Regla genérica para compilar archivos .c en .o
%.o: %.c
	@echo "Compilando $< en $@..."
	$(CC) $(FLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	@echo "Limpiando proyecto principal..."
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ)

# Limpieza completa
fclean: clean
	@echo "Eliminando ejecutables..."
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Reconstruir todo
re: fclean all

# Declarar objetivos que no son archivos
.PHONY: all clean fclean re
