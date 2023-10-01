CC = cc
GFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
NAME = philo 
SRC = is_error.c is_error_utils.c get_time.c\
		check_death.c malloc_all.c get_set_all.c\
		routine.c routine_utils.c\
		philo.c philo_utils.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -o $(NAME)

.c.o: 
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus

# -g -fsanitize=thread