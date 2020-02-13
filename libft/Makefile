NAME = libft.a
FLAGS = -Wall -Wextra -Werror

RED = "\033[0;31m"
GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"
CLEAR = "\033[0m"

SRC =   ft_atoi.c\
		ft_err_exit.c\
		ft_isascii.c\
		ft_memchr.c\
		ft_memset.c\
		ft_strcpy.c\
		ft_strncat.c\
		ft_strrchr.c\
		ft_bzero.c\
		ft_isdigit.c\
		ft_memcmp.c\
		ft_strcat.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strstr.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strncpy.c\
		ft_tolower.c\
		ft_isalpha.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_strcmp.c\
		ft_strlen.c\
		ft_strnstr.c\
		ft_toupper.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstadd_bk.c\
		ft_lstinsert.c\
		ft_lstdelat.c\
		ft_lstlen.c\
		ft_lstat.c\
		ft_ulltoa_base.c\
		ft_lltoa_base.c\
		ft_strup.c\
		ft_stradd.c\
		ft_strtrimc.c\
		get_next_line.c\
		stack.c\
		queue.c
SRC_PATH = ./

OBJ_PATH = ./lft_objs/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"libft.a created"$(CLEAR)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo $(RED)"Removed libft object files"$(CLEAR)

fclean:
	@/bin/rm -rf $(NAME)
	@echo $(RED)"Removed libft.a"$(CLEAR)

re: clean fclean all
