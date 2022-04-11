NAME = pipex

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADER = pipex.h

SRC = pipex.c \
		./src_pipex/ft_error.c \
		./src_pipex/ft_free.c \
		./src_pipex/ft_child.c \
		./src_pipex/ft_libft_functions.c \
		./src_pipex/ft_split.c \
		./src_pipex/ft_strjoin.c \
		./src_pipex/ft_substr.c \
		./src_pipex/ft_utils.c

OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -O2 $(OBJ) -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
#	cd libft && make clean
	@rm -f $(OBJ)
#	@rm -f $(OBJ_B)

fclean	:	clean
#	cd libft && make fclean
	@$(RM) $(NAME)
#	@$(RM) $(NAME_B)

re	:	fclean all

