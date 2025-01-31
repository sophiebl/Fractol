NAME	= fractol

SRC		= main.c \
			key.c \
			mouse.c \
			mandelbrot.c \
			julia.c \
			burning.c \
			draw.c \
			error.c \
			window.c 

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 

MLX		= ./mlx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -o $@ -c $< -I $(INCDIR)

$(NAME): $(OBJ) 
	make -C $(MLX)
	make -C $(FT) 
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all obj fclean clean re
