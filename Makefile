
NAME		= cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address

LIBFT		= libft.a
LIBFTDIR	= ./includes/libft
INC=/usr/include/
INCLIB=$(INC)/../lib

MINILIBX	= minilibx-linux
MINILIBA	= libmlx_Linux.a

SRCDIR		= ./src/
SRC			= draw_utils.c free.c general.c general_2.c init_1.c init_2.c keys.c keys_aux.c main.c map_copy.c move_player.c \
				raycast_1.c raycast_2.c validation.c validation_element.c validation_image.c validation_map.c
OBJ			= $(addprefix $(SRCDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBA) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBA) -o $@ -L$(INCLIB) -lXext -lX11 -lm -lbsd

$(MINILIBA):
		make -C $(MINILIBX)
		cp $(MINILIBX)/$(MINILIBA) .

$(LIBFT):
		make -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFT) .

clean:
		make -C $(LIBFTDIR) clean
		rm -f $(SRCDIR)*.o

fclean: clean
		make -C $(LIBFTDIR) fclean
		rm -f $(NAME) $(LIBFT) $(MINILIBA)

re: fclean all

