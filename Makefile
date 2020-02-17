NAME = fdf
SRC_PATH = ./srcs/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/
INC_PATH = ./includes/

LFT = libft.a
MLX = libmlx.a

FDF_INC = -I $(INC_PATH)
LFT_INC = -I $(LFT_PATH)
MLX_INC = -I $(MLX_PATH)

LFT_LINK = -L $(LFT_PATH) -l ft
MLX_LINK = -L $(MLX_PATH) -l mlx -framework OpenGL -framework APPkit

FLAGS = -Wall -Werror -Wextra
TEST_FLAGS = -g

RED  = "\033[0;31m"
GREEN  = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"
CLEAR = "\033[0m"

SRC_NAME =	draw.c\
			input.c\
			math.c\
			main.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

.PHONY: all clean fclean re

all: $(LFT) $(NAME)

$(LFT):
	@make -C $(LFT_PATH)
	@make -C $(MLX_PATH)

$(NAME): $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(FDF_INC) $(LFT_INC) $(MLX_INC) $(LFT_LINK) $(MLX_LINK) $(SRC)
	@echo $(GREEN)"fdf compiled" $(CLEAR)

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@/bin/rm -f $(OBJ)
	@echo $(RED)"Deleted object files" $(CLEAR)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM
	@echo $(RED)"Deleted executable files" $(CLEAR)

re: fclean all


test: fclean $(LFT)
	@gcc $(TEST_FLAGS) -o $(NAME) $(FDF_INC) $(LFT_INC) $(MLX_INC) $(LFT_LINK) $(MLX_LINK) $(SRC)
	@echo $(CYAN)"fdf test compiled" $(CLEAR)