NAME = libft.a

CC = clang

FLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c	\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_reversestr.c ft_free2darr.c \
		get_next_line.c ft_ltoa.c ft_itoa_base.c ft_ltoa_base.c	ft_ultoa.c ft_printf.c parser.c ft_format_create.c \
		ft_print_type.c print_utils.c print_char.c print_unsigned_decimal.c print_hex.c print_decimal.c print_octal.c \
		print_string.c print_ptr.c print_float.c float_utils.c roundf_utils.c ft_ltoi.c ft_swap.c ft_isdigitstr.c

OBJECTS = $(SRCS:.c=.o)

INCLUDES = libft.h

# ifeq ($(UNAME_S),Linux)
	# FLAGS += -fPIC
# endif

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) -c $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re:	fclean all
