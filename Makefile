SRC = recieve_args.c put_calls.c outputs.c helpers.c put_long_calls.c put_long_long_calls.c \
put_short_calls.c put_to_char_calls.c put_to_max_calls.c put_z_calls.c put_unicode.c \
put_unicode_helps.c printf_helpers.c get_spec.c itoa_base.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
INC_DIR = includes
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME) $(SRC)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@echo "create ft_printf"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $< -I$(INC_DIR)

clean:
	@rm -f $(OBJ)
	@echo "Delete objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Delete $(NAME)"

re: fclean all