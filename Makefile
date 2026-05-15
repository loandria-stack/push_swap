# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 11:16:39 by loandria          #+#    #+#              #
#    Updated: 2026/04/22 09:16:10 by tojorana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf
SRC =\
	count_disorder.c\
	push_op.c\
	reverse_rotate_op.c\
	rotate_op.c\
	simple_algo.c\
	stack_init.c\
	swap_op.c\
	swap_utils.c\
	main.c\
	is_atoi.c\
	sort_3_nb.c\
	stack_size.c\
	complex_algo.c\
	adaptive_str.c\
	bench_utils.c\
	bench_mod.c\
	main_utils.c\
	medium_algo.c\
	put_index.c\
	get_max.c\
	parsing.c\
	is_split.c\
	sort_5_nb.c\
	sort_4_nb.c\
	get_condition.c\
	ft_printf/ft_convert.c\
	ft_printf/ft_format.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_puthexa.c\
	ft_printf/ft_putptr.c

OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
