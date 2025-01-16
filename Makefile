# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 09:21:42 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/01/16 09:22:10 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Eyad
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
EXEC_DIR = exec/

SRC = main ft_strlen
SRC_FILES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
INC_FILES = $(addprefix $(INC_DIR), main.h)

all: $(OBJ_DIR) $(EXEC_DIR) $(EXEC_DIR)/$(NAME)

# Only relink if object files are newer than executable
$(EXEC_DIR)/$(NAME): $(OBJ_FILES) | $(EXEC_DIR)
	@$(CC) $(FLAGS) -o $@ $^

# Only recompile if source files or headers are newer than object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_FILES) | $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(EXEC_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up object directory"

fclean: clean
	@rm -rf $(EXEC_DIR)
	@echo "Executable directory deleted"

re: fclean all

.PHONY: all clean fclean re