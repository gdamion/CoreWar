NAME = corewar

SRCS = srcs/vm/main.c
SRCS += srcs/vm/comands/add.c srcs/vm/comands/aff.c srcs/vm/comands/and.c srcs/vm/comands/args_parsing.c srcs/vm/comands/comands_checker.c \
		srcs/vm/comands/fork.c srcs/vm/comands/get_arg_values.c srcs/vm/comands/ld.c srcs/vm/comands/ldi.c srcs/vm/comands/lfork.c \
		srcs/vm/comands/live.c srcs/vm/comands/lld.c srcs/vm/comands/or.c srcs/vm/comands/st.c srcs/vm/comands/sti.c srcs/vm/comands/sub.c \
		srcs/vm/comands/xor.c srcs/vm/comands/zjmp.c srcs/vm/comands/lldi.c
SRCS += srcs/vm/game/game.c srcs/vm/game/game.c srcs/vm/game/get_comands.c srcs/vm/game/live_checker.c
SRCS += srcs/vm/parser/checker.c srcs/vm/parser/read_file.c srcs/vm/parser/parser.c srcs/vm/parser/n_flag.c srcs/vm/parser/dump.c
SRCS += srcs/vm/initialisation/carrs_funcs.c srcs/vm/initialisation/free_structs.c srcs/vm/initialisation/init_carriage.c \
		srcs/vm/initialisation/init_player.c srcs/vm/initialisation/init_structures.c
SRCS += srcs/vm/printing/helpers.c srcs/vm/printing/helpers2.c srcs/vm/printing/helpers3.c srcs/vm/printing/print_help.c \
		srcs/vm/printing/print_v_31.c srcs/vm/printing/print_v_31_2.c srcs/vm/printing/print_v_31_3.c
SRCS += srcs/vm/visual/brigtness.c srcs/vm/visual/visual_helper.c srcs/vm/visual/visual_helper2.c srcs/vm/visual/visual_helper3.c \
		srcs/vm/visual/visual_helper4.c srcs/vm/visual/visual_helper5.c srcs/vm/visual/visual.c srcs/vm/visual/visual2.c

LIB_SRC = libft
OBJDIR = objs

ASM_DIR = srcs/asm/assembler

CC = clang

FLAGS = -lm -Llibft -lft -I corewar.h

FLAGS += -Wall -Wextra -Werror

FLAGS += -lncurses

OBJECTS := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(CC) -o $@ $^ $(FLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p '$(@D)'
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	$(MAKE) -C $(LIB_SRC) clean

fclean: clean
	rm -rf $(OBJDIR)
	@make -C $(LIB_SRC) fclean
	rm -rf $(NAME)

re_debug: debug

re: fclean all
