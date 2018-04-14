# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 22:35:46 by dphuntso          #+#    #+#              #
#    Updated: 2018/03/26 15:58:48 by dphuntso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fillit
SRCS    = 	board_helper.c check_tetris.c fillit.c get_tetris.c helper.c read_file.c solve_helper.c solve_square.c valid_input.c
OFILES    = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cd libft && make
	gcc -Wall -Wextra -Werror $(SRCS) -L ./libft -lft
	mv a.out fillit

clean:
	cd libft && make clean
	rm -f $(OFILES)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all