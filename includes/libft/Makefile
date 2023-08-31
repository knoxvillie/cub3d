NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES_MANDATORY = ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_printf.c \
		print_c.c \
		print_d.c \
		print_p.c \
		print_per.c \
		print_s.c \
		print_u.c \
		print_x.c \
		utils.c \
		get_next_line_bonus.c

OBJECTS_MANDATORY = $(SOURCES_MANDATORY:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS_MANDATORY)
	ar rc $(NAME) $(OBJECTS_MANDATORY)

clean:
	rm -rf $(OBJECTS_MANDATORY)

fclean: clean
	rm -rf $(NAME)

re: fclean all
