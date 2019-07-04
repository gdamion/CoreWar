# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 21:32:16 by gdamion-          #+#    #+#              #
#    Updated: 2019/07/04 22:37:30 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIB = -L$(LIB_DIR)
INC = -I$(INC_DIR) -I$(INC_LIB_DIR)

LIB_DIR = ./libft/
LIB_FILE = $(LIB)libft.a
INC_LIB_DIR = $(LIB_DIR)includes/

INC_LIST =	com.h \
			asm.h \
			corewar.h \
			op.h

INC_DIR = ./inc/
INC = $(addprefix $(INC_DIR), $(INC_LIST))

################# ASM #################
SRC_DIR = ./src/
SRC_LIST =

SRC_ASM = $(addprefix $(SRC_DIR), $(SRC_LIST))
#######################################

############### COREWAR ###############

#######################################

Obj_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(Obj_DIR), $(OBJ_LIST))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(LIBFT) $(Obj_DIR) $(OBJECTS)
	@$(CC) $(LIBFT) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(Obj_DIR):
	@mkdir -p $(Obj_DIR)
	@echo "$(NAME): $(GREEN)$(Obj_DIR) was created$(RESET)"

$(Obj_DIR)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(Obj_DIR)
	@echo "$(NAME): $(RED)$(Obj_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
