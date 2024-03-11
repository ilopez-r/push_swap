# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:17:13 by ilopez-r          #+#    #+#              #
#    Updated: 2024/03/11 13:28:35 by ilopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

FLAGS = -Wall -Werror -Wextra

FILES = src/push_swap.c\
		src/check.c\
		src/fill_and_assign.c\
		src/select_algorithm.c\
		src/rotates_push_swap.c\
		src/position.c\
		src/movement.c\
		src/final_movement.c\

BONUS = srcb/checker.c\
		srcb/check.c\
		srcb/fill_and_assign.c\
		srcb/select_algorithm.c\
		srcb/rotates_push_swap.c\
		srcb/position.c\
		srcb/movement.c\
		srcb/final_movement.c\

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

LIBFT_PATH = ./libftc

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME) $(LIBFT)

$(LIBFT) :
	@make -s -C $(LIBFT_PATH)

$(NAME) : $(OBJS) $(LIBFT)
	@gcc $(FLAGS) $(FILES) $(LIBFT)  -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT)
	@gcc $(FLAGS) $(BONUS) $(LIBFT)  -o $(NAME_BONUS)

$(OBJS) : $(FILES)
	@gcc $(FLAGS) -c $< -o $@

$(OBJS_BONUS) : $(BONUS) 
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS) $(OBJS_BONUS)
	@make clean -s -C $(LIBFT_PATH)

fclean: clean
	@rm -fr $(NAME) $(NAME_BONUS) 
	@rm -f file2
	@make fclean -s -C $(LIBFT_PATH)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY : all clean fclean re bonus