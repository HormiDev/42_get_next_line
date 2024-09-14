
NAME = get_next_line.out

NAME_BONUS = get_next_line_bonus.out

SRC = get_next_line.c get_next_line_utils.c main.c

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c

FLAGS = -Wall -Wextra -Werror

CC = gcc

compile:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

compile_bonus:
	$(CC) $(FLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

all: compile

bonus: compile_bonus

