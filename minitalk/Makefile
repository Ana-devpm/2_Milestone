# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 15:48:43 by afailde-          #+#    #+#              #
#    Updated: 2025/02/25 16:05:33 by afailde-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC              =   cc
FLAGS           =   -Wextra -Werror -Wall -g3 -fsanitize=address
RM              =   rm -f

# Colors
GREEN       =   \e[0;32m
YELLOW      =   \e[0;33m
BLUE        =   \e[0;34m
RED         =   \e[0;31m
NC          =   \e[0m  # No Color (reset)

# Executables
NAME_SERVER     =   server
NAME_CLIENT     =   client

# Source files and objects for server, client, and utils
SERVER_SRC      =   server.c
CLIENT_SRC      =   client.c
LIBFT           =   libft/libft.a
SERVER_OBJ      =   server.o
CLIENT_OBJ      =   client.o

# Main target
all: $(NAME_SERVER) $(NAME_CLIENT)

# Compile the server
$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT) 
	@echo -e "$(YELLOW)⚙️  Compiling $(NAME_SERVER)...$(NC)"
	$(CC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_SERVER)
	@echo -e "$(GREEN)✅ $(NAME_SERVER) created!$(NC)"

# Compile the client
$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo -e "$(YELLOW)⚙️  Compiling $(NAME_CLIENT)...$(NC)"
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_CLIENT)
	@echo -e "$(GREEN)✅ $(NAME_CLIENT) created!$(NC)"

# Compile libft
$(LIBFT):
	@echo -e "$(BLUE)📚 Compiling Libft...$(NC)"
	@make -sC libft
	@echo -e "$(GREEN)✅ Libft compiled successfully!$(NC)"

# Generic rule to compile .c files into .o
%.o: %.c
	@echo -e "$(BLUE)🛠️  Compiling $< into $@...$(NC)"
	$(CC) $(FLAGS) -c $< -o $@

# Clean object files
clean:
	@make -sC libft fclean
	@echo -e "$(RED)🗑️  Cleaning main project...$(NC)"
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

# Full cleanup
fclean: clean
	@echo -e "$(RED)🚮 Removing executables...$(NC)"
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Rebuild everything
re: fclean all

# Declare targets that are not files
.PHONY: all clean fclean re
