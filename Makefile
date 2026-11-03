NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= includes

LIBFT_DIR	= libft
MLX_DIR		= minilibx

LIBFT	= $(LIBFT_DIR)/libft.a
MLX		= $(MLX_DIR)/libmlx.a

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC		= main.c

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
