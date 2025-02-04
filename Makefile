# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 22:28:21 by rbardet-          #+#    #+#              #
#    Updated: 2025/02/03 05:32:15 by rbardet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

SOURCES =	Sources/main.c \
			Sources/stack_utils.c \
			Sources/push_swap_utils.c \
			Sources/find_lowest_cost.c \
			Sources/move_to_top.c \
			Sources/reverse_top_element.c \
			Sources/move_top_element.c \
			Sources/rotate_stack.c \
			Sources/reverse_rotate_stack.c \
			Sources/special_case.c \
			Sources/sort_in_a.c \
			Sources/sort_in_b.c \
			Sources/two_arg_case.c \
			Sources/normalize_stack.c \
			Sources/normalize_stack_big.c \

SOURCES_BONUS =	checker_bonus/main_bonus.c \
				checker_bonus/reverse_top_element_bonus.c \
				checker_bonus/move_top_element_bonus.c \
				checker_bonus/rotate_stack_bonus.c \
				checker_bonus/reverse_rotate_stack_bonus.c \
				checker_bonus/checker_bonus.c \
				checker_bonus/utils_bonus.c \
				checker_bonus/utils_bonus2.c \

INCLUDE = -I SOURCES -I libft

LIBFTPATH = LIBFT_V2
LIBFT = $(LIBFTPATH)/libft.a

OBJECTS = $(SOURCES:.c=.o)
OBJECTS2 = $(SOURCES_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDE)
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

bonus: $(OBJECTS2) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJECTS2) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all bonus

.PHONY: all clean fclean re bonus


