# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 18:39:58 by lmaron-g          #+#    #+#              #
#    Updated: 2019/07/05 13:51:55 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

42FLAGS = -Wall -Wextra -Werror

SORT_D = $(addprefix ./srcs/sort/,$(SORT))
OTHER_D = $(addprefix ./srcs/other/,$(OTHER))
OUTPUT_D = $(addprefix ./srcs/output/,$(OUTPUT))
MEMORY_D = $(addprefix ./srcs/memory/,$(MEMORY))
STRINGS_D = $(addprefix ./srcs/strings/,$(STRINGS))
UTIL_IS_D = $(addprefix ./srcs/util_is/,$(UTIL_IS))
FT_PRINTF_D = $(addprefix ./srcs/ft_printf/,$(FT_PRINTF))
TRANSLATION_D = $(addprefix ./srcs/translation/,$(TRANSLATION))
LINKED_LISTS_D = $(addprefix ./srcs/linked_lists/,$(LINKED_LISTS))

SRCS = 		$(OTHER) $(SORT) $(OUTPUT) $(MEMORY) $(STRINGS) $(UTIL_IS) \
			$(FT_PRINTF) $(TRANSLATION) $(LINKED_LISTS)

SRC_DIRS = 	$(OTHER_D) $(SORT_D) $(OUTPUT_D) $(MEMORY_D) $(STRINGS_D) $(UTIL_IS_D) \
 			$(FT_PRINTF_D) $(TRANSLATION_D) $(LINKED_LISTS_D)

OBJ_D = objs
OBJS  = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

MEMORY = 		ft_memccpy.c       \
				ft_memchr.c        \
				ft_memcmp.c        \
				ft_memcpy.c        \
				ft_memmove.c       \
				ft_memset.c        \
				ft_memalloc.c      \
				ft_memdel.c        \

STRINGS = 		ft_catpro.c       \
				ft_strcat.c        \
				ft_strchr.c        \
				ft_strcmp.c        \
				ft_strcpy.c        \
				ft_strdup.c        \
				ft_strlcat.c       \
				ft_strlen.c        \
				ft_strncat.c       \
				ft_strncmp.c       \
				ft_strncpy.c       \
				ft_strnstr.c       \
				ft_strrchr.c       \
				ft_strstr.c        \
				ft_strnew.c        \
				ft_strdel.c        \
				ft_findchar.c      \
				ft_strclr.c        \
				ft_striter.c       \
				ft_striteri.c      \
				ft_strmap.c        \
				ft_strmapi.c       \
				ft_strequ.c        \
				ft_strnequ.c       \
				ft_strsub.c        \
				ft_strjoin.c       \
				ft_strtrim.c       \
				ft_strsplit.c      \
				get_next_line.c    \

OUTPUT =		ft_putchar.c       \
				ft_putstr.c        \
				ft_putendl.c       \
				ft_putnbr.c        \
				ft_putchar_fd.c    \
				ft_putstr_fd.c     \
				ft_putendl_fd.c    \
				ft_putnbr_fd.c     \
				print_error.c      \

FT_PRINTF = 	ft_printf.c        \
				main_utilities.c   \
				print_cspf.c       \
				print_diouxx.c     \
				spec_lenghts.c     \
				util_find.c        \
				additional.c       \
				print_unicode.c    \
				print_unicode_cs.c \
				util_is.c          \
				ft_putstr_free.c   \
				ft_putchar_free.c  \

UTIL_IS =		ft_isalnum.c       \
				ft_isalpha.c       \
				ft_isascii.c       \
				ft_isdigit.c       \
				ft_isprint.c       \

TRANSLATION =	ft_atoi.c          \
				ft_itoa.c          \
				ft_tolower.c       \
				ft_toupper.c       \
				util_translation.c \

LINKED_LISTS =	ft_lstnew.c        \
				ft_lstdelone.c     \
				ft_lstdel.c        \
				ft_lstadd.c        \
				ft_lstiter.c       \
				ft_lstmap.c        \
				ft_lstfree.c       \
				ft_lstaddend.c     \
				ft_lstfreeone.c    \

OTHER = 		ft_bzero.c         \
				ft_pow.c           \
				ft_nbrlen.c        \
				find_min.c         \
				find_max.c         \
				duplicates.c       \

SORT = 			init.c             \
				stack.c            \
				quicksort.c        \
				heapsort.c         \
				insertsort.c       \
				mergesort.c        \
				selectionsort.c    \

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC_DIRS)
	@gcc $(42FLAGS) -c $(SRC_DIRS) -I ./includes
	@mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) binary was built$(RESET)"

clean:
	@rm -rf $(OBJ_D)/
	@echo "$(NAME): $(RED)$(OBJ_D)/ folder was deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME) binary was deleted$(RESET)"

re: fclean all
