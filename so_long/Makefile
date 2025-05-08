# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 11:41:52 by afailde-          #+#    #+#              #
#    Updated: 2025/05/08 21:27:46 by afailde-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler and flags
CC			=	cc
CFLAGS		=	-g3 -Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -fr
INCLUDE		=	-I

#MLX42
LIBMLX		= ./MLX42
HEADERS		= -I ./include -I $(LIBMLX)/include
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

#Colors
NC			=	\e[0m #No color (reset)
RED			=	\e[0;31m
GREEN		=	\e[0;32m
YELLOW		=	\e[0;33m
BLUE		=	\e[0;34m

#Program name
NAME		=	so_long

#Map files
MAP_FILES 	= 	create_map.c \
				build_map.c \
				utils_map.c \
		  		check_map.c \
				flood_fill.c \
				validate_path.c
#Clean files
CLEAN_FILES	=	clean_up_graphics.c

#Game files
GAME_FILES	=	init_mlx.c \
				player.c \
				player_moves.c \
				collectibles.c \
				collectible_resize.c \
				tiles.c

#Checker files
CHECKER_FILES 	= 	check_extension.c

#Source file
SRCS 		=  so_long.c

SRC = $(addprefix src/, $(SRCS))

CLEAN_UP = $(addprefix src/clean/, $(CLEAN_FILES))

CHECK = $(addprefix src/args_checker/, $(CHECKER_FILES))

GAME = $(addprefix src/game/, $(GAME_FILES))

MAP = $(addprefix src/map/, $(MAP_FILES))

PACKAGES = $(MAP) $(CLEAN_UP) $(CHECK) $(GAME) $(SRC) 

#Object files
OBJ = $(PACKAGES:%.c=%.o)

#Compilation rules
all: libmlx $(NAME) 

libmlx:
	@echo "$(BLUE)📚 Compiling MLX42...$(NC)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4
	make -C $(LIBMLX)/build
	@echo "$(GREEN)✅ MLX42 compiled successfully!$(NC)"

#Executable
LIBFT_DIR	=	utils/libft
LIBFT	=	$(LIBFT_DIR)/libft.a

#Compile libft
$(LIBFT):
	@echo "$(BLUE)📚 Compiling Libft...$(NC)"
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)✅ Libft compiled successfully!$(NC)"

#Compile so_long
$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ Compilation successful!$(NC)"

#Compile .o files 
%.o: %.c
	@echo "$(BLUE)Compiling $< → $@...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Clean .o
clean:
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)🗑️  Cleaning .o files...$(NC)"
	@$(RM) $(OBJ)
	@$(RM) $(LIBMLX)/build

#Fclean
fclean: clean
	@echo "$(RED)🗑️  Removing executables and libraries...$(NC)"
	@$(RM) $(NAME) $(OBJ)
	
#Re
re: fclean all

#PHONY
.PHONY: all clean fclean reargs_checker.c libmlx
