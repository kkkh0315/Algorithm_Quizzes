NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MLXDIR = minilibx
MLX = mlx
SRCS = raycasting.c 
OBJS = $(SRCS:.c=.o)
INCS = ./incs
RM = rm -rf

all : $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(MLXFLAGS) -o $(NAME) -L$(MLXDIR) -l$(MLX) $(SRCS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCS)

lib:
	make -C $(MLXDIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(MLXDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

