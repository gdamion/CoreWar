# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 21:32:16 by gdamion-          #+#    #+#              #
#    Updated: 2019/07/27 16:23:09 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME = asm
VM_NAME = corewar

CC = gcc
FLAGS = -Wall -Werror -Wextra

################# LIB #################
LIB_DIR = ./libft/
LIB_NAME = libft.a
LIB_FILE = $(LIB_DIR)$(LIB_NAME)
LIB = -L$(LIB_DIR)
#######################################

################# INC #################

INC_LIB_DIR = $(LIB_DIR)includes/
INC_LIST =	com.h \
			asm.h \
			asm_error.h \
			asm_ops.h \
			op.h

INC_DIR = ./inc/
INC = -I$(INC_DIR) -I$(INC_LIB_DIR)
HEADERS = $(addprefix $(INC_DIR), $(INC_LIST))
#######################################

OBJ_DIR = obj/
################# ASM #################
SRC_ASM_DIR = ./src/asm_src/
SRC_ASM_LIST =	buf_write.c \
				error_msgs.c \
				error.c \
				file_gen.c \
				free_data.c \
				get_line.c \
				init.c \
				lexical.c \
				main.c \
				process_info.c \
				read_file.c \
				syntax.c \
				utilities.c

SRC_ASM = $(addprefix $(SRC_ASM_DIR), $(SRC_ASM_LIST))

OBJ_ASM_DIR = $(OBJ_DIR)asm/
OBJ_ASM_LIST = $(patsubst %.c, %.o, $(SRC_ASM_LIST))
OBJ_ASM	= $(addprefix $(OBJ_ASM_DIR), $(OBJ_ASM_LIST))
#######################################

################## VM #################
SRC_VM_DIR = ./src/vm_src/
SRC_VM_LIST =	main.c


SRC_VM = $(addprefix $(SRC_VM_DIR), $(SRC_VM_LIST))

OBJ_VM_DIR = $(OBJ_DIR)vm/
OBJ_VM_LIST = $(patsubst %.c, %.o, $(SRC_VM_LIST))
OBJ_VM	= $(addprefix $(OBJ_VM_DIR), $(OBJ_VM_LIST))
#######################################

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(LIB_FILE) $(ASM_NAME) $(VM_NAME)

################ ASM COMPILE #################
$(ASM_NAME): $(OBJ_ASM_DIR) $(OBJ_ASM)
	@echo "\n$(ASM_NAME): $(GREEN)Object files were created$(RESET)"
	@$(CC) $(LIB_FILE) $(FLAGS) $(LIB) $(INC) $(OBJ_ASM) -o $(ASM_NAME)
	@echo "$(ASM_NAME): $(GREEN)$(ASM_NAME) binary was created!$(RESET)"

$(OBJ_ASM_DIR):
	@mkdir -p $(OBJ_ASM_DIR)
	@echo "$(ASM_NAME): $(GREEN)$(OBJ_ASM_DIR) folder was created!$(RESET)"

$(OBJ_ASM_DIR)%.o : $(SRC_ASM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@
	@echo "$(GREEN).$(RESET)\c"
##############################################

################# VM COMPILE #################
$(VM_NAME): $(OBJ_VM_DIR) $(OBJ_VM)
	@echo "\n$(VM_NAME): $(GREEN)Object files were created$(RESET)"
	@$(CC) $(LIB_FILE) $(FLAGS) $(LIB) $(INC) $(OBJ_VM) -o $(VM_NAME)
	@echo "$(VM_NAME): $(GREEN)$(VM_NAME) binary was created$(RESET)"

$(OBJ_VM_DIR):
	@mkdir -p $(OBJ_VM_DIR)
	@echo "$(VM_NAME): $(GREEN)$(OBJ_VM_DIR) folder was created$(RESET)"

$(OBJ_VM_DIR)%.o : $(SRC_VM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@
	@echo "$(GREEN).$(RESET)\c"
##############################################

$(LIB_DIR)$(LIB_NAME):
	@echo "$(LIB_DIR)$(LIB_NAME): $(GREEN)Creating $()...$(RESET)"
	@$(MAKE) -sC $(LIB_DIR)
	@echo "$(LIB_DIR)$(LIB_NAME): $(GREEN)Library $(LIB_NAME) was created!$(RESET)"

clean:
	@$(MAKE) -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(ASM_NAME) & $(VM_NAME): $(RED)$(OBJ_DIR) folder was deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIB_DIR) fclean
	@rm -f $(ASM_NAME)
	@echo "$(ASM_NAME): $(RED)$(ASM_NAME) binary was deleted$(RESET)"
	@rm -f $(VM_NAME)
	@echo "$(VM_NAME): $(RED)$(VM_NAME) binary was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
