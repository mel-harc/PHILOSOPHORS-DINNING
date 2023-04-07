HEADER = philo.h

CC = cc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra

NAME = philo

SRC = philo.c parsing.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(OBJ) -o $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re