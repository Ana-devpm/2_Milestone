# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 12:26:42 by afailde-          #+#    #+#              #
#    Updated: 2025/02/25 16:07:07 by afailde-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler and flags
CC			=	cc
FLAGS		=	-Wextra -Werror -Wall -g3 -fsanitize=address
RM			=	rm -f
INCLUDE		=	-I

# Colors
GREEN       =   \e[0;32m
YELLOW      =   \e[0;33m
BLUE        =   \e[0;34m
RED         =   \e[0;31m
NC          =   \e[0m  # No Color (reset)

#Program name
NAME		=	push_swap

#Sources
SRC			=	push_swap.c \
				parse.c\
				hard_sort.c \
				sort.c \
				nodes.c \
				move_cost.c \
				push_moves.c \
				reverse_moves.c \
				rotate_moves.c \
				swap_moves.c

#Object files
OBJ = $(SRC:.c=.o)

#Compilation rules
all: $(NAME)

#Exectuable
LIBFT		=	libft/libft.a

#Compile libft
$(LIBFT):
	@echo -e "$(BLUE)📚 Compiling Libft...$(NC)"
	@make -sC libft
	@echo -e "$(GREEN)✅ Libft compiled successfully!$(NC)"
#Compile push_swap
$(NAME): $(OBJ) $(LIBFT)
	@echo -e "$(YELLOW)Compiling $(NAME)...$(NC)"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)✅ Compilation successful!$(NC)"

#Compile .o files 
%.o: %.c
	@echo -e "$(BLUE)Compiling $< → $@...$(NC)"
	$(CC) $(FLAGS) -c $< -o $@

#Clean .o
clean:
	make -sC libft fclean
	@echo -e "$(RED)🗑️  Cleaning .o files...$(NC)"
	$(RM) $(OBJ)

#Fclean
fclean: clean
	@echo -e "$(RED)🗑️  Removing executables and libraries...$(NC)"
	$(RM) $(NAME) $(OBJ)

#Re
re: fclean all

#.PHONY
.PHONY: all clean fclean re
