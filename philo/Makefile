CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME = philo
SRC = is_error.c is_error_utils.c\
		check_death.c malloc_all.c get_set_all.c\
		routine.c routine_utils.c\
		philo.c philo_utils.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -g -fsanitize=thread -o $(NAME)

.c.o: 
	$(CC) -c $< -g -fsanitize=thread -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus