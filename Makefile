.PHONY: clean all re fclean
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRC = ft_cmd.c ft_printerr.c ft_pipex.c ft_files.c
LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "done"
$(NAME):
	@CC $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all