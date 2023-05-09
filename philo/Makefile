# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 19:42:14 by mel-harc          #+#    #+#              #
#    Updated: 2023/05/09 22:20:33 by mel-harc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = philo.h

CC = cc

RM = rm -rf

FLAGS = -g -Wall -Werror -Wextra  -fsanitize=thread

NAME = philo

SRC = philo.c parsing.c ft_atoi.c init_data.c creat_philo.c error.c \
		creat_thread.c routine.c time.c check_is_died.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re