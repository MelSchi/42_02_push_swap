# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:21:28 by mschiman          #+#    #+#              #
#    Updated: 2022/01/15 12:55:23 by mschiman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	src/main.c \
		src/push_swap_buckets.c \
		src/push_swap_input_checks.c \
		src/push_swap_lst_create_free.c \
		src/push_swap_lst_infos.c \
		src/push_swap_lst_push.c \
		src/push_swap_moves.c \
		src/push_swap_sorting.c \
		src/push_swap_sort_few.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
CC =	gcc
RM = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re