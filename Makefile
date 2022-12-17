# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:44:01 by mpagani           #+#    #+#              #
#    Updated: 2022/12/17 12:25:53 by mpagani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
SRCS 		= main.c push_swap.c ./operations/op_s.c ./operations/op_r.c \
			./operations/op_p.c ./operations/op_rr.c \
			./backroom/stack_size.c ./backroom/stack_add_front.c ./backroom/stack_free.c \
			./backroom/stack_add_back.c ./backroom/stack_last.c ./backroom/stack_new.c \
			./backroom/arr_len.c \
			./find_move_target/moving_target.c ./find_move_target/find_target.c \
			./find_move_target/find_min_max.c ./find_move_target/choosing_index.c\
			./error/check_error.c ./error/small_checking.c
CC 			= cc
AR 			= ar
RM 			= rm -f
SRCS_DIR	= ./srcs
INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
BUILD_DIR	= build
OBJS 		= $(SRCS:%.c=$(BUILD_DIR)/%.o)
CFLAGS 		= -Wall -Werror -Wextra
HEADER_FILE = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Done!"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS_DIR)/$(HEADER_FILE) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR) -I$(LIBFT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
