# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/12/17 16:24:16 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAGS = -Wall -Wextra -Werror -g
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main validation  validation_sup1 validation_sup2 validation_sup3 \
		read_memory game show operation init\
		copy_carriage convert_type get_args op_helper\
		op_add op_aff op_and op_fork op_ld op_ldi op_lfork op_live op_lld op_lldi \
		op_or op_st op_sti op_sub op_xor op_zjmp

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c includes/corewar.h includes/op.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs make_lib $(OBJS) libft/libft.a 
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅ Corewar compiled!

make_lib:
	@make -C libft

objs:
		@mkdir objs 2> /dev/null || true

clean:
		@make -C libft/ clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
