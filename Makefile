# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 21:32:16 by gdamion-          #+#    #+#              #
#    Updated: 2019/07/04 23:30:27 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME = asm
VM_NAME = corewar

CC = gcc
FLAGS = -Wall -Werror -Wextra

################# LIB #################
LIB = -L$(LIB_DIR)
LIB_DIR = ./libft/
LIB_FILE = $(LIB)libft.a
#######################################

################# INC #################
INC = -I$(INC_DIR) -I$(INC_LIB_DIR)
INC_LIB_DIR = $(LIB_DIR)includes/

INC_LIST =	com.h \
			asm.h \
			corewar.h \
			op.h

INC_DIR = ./inc/
HEADERS = $(addprefix $(INC_DIR), $(INC_LIST))
#######################################

OBJ_DIR = obj/
################# ASM #################
SRC_ASM_DIR = ./src/asm/
SRC_ASM_LIST =	op.c \


SRC_ASM = $(addprefix $(SRC_ASM_DIR), $(SRC_ASM_LIST))

OBJ_ASM_DIR = $(OBJ_DIR)asm/
OBJ_ASM_LIST = $(patsubst %.c, %.o, $(SRC_ASM_LIST))
OBJ_ASM	= $(addprefix $(OBJ_ASM_DIR), $(OBJ_ASM_LIST))
#######################################

################## VM #################
SRC_VM_DIR = ./src/vm/
SRC_VM_LIST =	op.c \


SRC_VM = $(addprefix $(SRC_VM_DIR), $(SRC_VM_LIST))

OBJ_VM_DIR = $(OBJ_DIR)vm/
OBJ_VM_LIST = $(patsubst %.c, %.o, $(SRC_VM_LIST))
OBJ_VM	= $(addprefix $(OBJ_VM_DIR), $(OBJ_VM_LIST))
#######################################

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean

all: $(LIB_FILE) $(ASM_NAME) $(VM_NAME)

################ ASM COMPILE #################
$(ASM_NAME): $(OBJ_ASM_DIR) $(OBJ_ASM)
	@$(CC) $(LIB_FILE) $(FLAGS) $(LIB) $(INC) $(OBJ_ASM) -o $(ASM_NAME)
	@echo "$(ASM_NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_ASM_DIR):
	@mkdir -p $(OBJ_ASM_DIR)
	@echo "$(ASM_NAME): $(GREEN)$(OBJ_ASM_DIR) was created$(RESET)"

$(OBJ_ASM_DIR)%.o : $(SRC_ASM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@
	@echo "$(GREEN).$(RESET)\c"
	@echo "\n$(ASM_NAME): $(GREEN)object files were created$(RESET)"
##############################################

################# VM COMPILE #################
$(VM_NAME): $(OBJ_VM_DIR)$(OBJ_VM)
	@$(CC) $(LIB_FILE) $(FLAGS) $(LIB) $(INC) $(OBJ_VM) -o $(VM_NAME)
	@echo "$(VM_NAME): $(GREEN)$(VM_NAME) was created$(RESET)"

$(OBJ_VM_DIR):
	@mkdir -p $(OBJ_VM_DIR)
	@echo "$(VM_NAME): $(GREEN)$(OBJ_VM_DIR) was created$(RESET)"

$(OBJ_VM_DIR)%.o : $(SRC_VM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@
	@echo "$(GREEN).$(RESET)\c"
	@echo "\n$(VM_NAME): $(GREEN)object files were created$(RESET)"
##############################################

$(LIB):
	@echo "$(LIB_FILE): $(GREEN)Creating $()...$(RESET)"
	@$(MAKE) -sC $(LIB_DIR)

clean:
	@$(MAKE) -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIB_FILE)
	@echo "$(NAME): $(RED)$(LIB_FILE) was deleted$(RESET)"
	@rm -f $(ASM_NAME)
	@echo "$(ASM_NAME): $(RED)$(ASM_NAME) was deleted$(RESET)"
	@rm -f $(VM_NAME)
	@echo "$(VM_NAME): $(RED)$(VM_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
