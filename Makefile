# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 18:20:25 by rgendry           #+#    #+#              #
#    Updated: 2019/12/18 20:40:04 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror

ASM = asm
SRC_ASM_NAME = main.c \
			   parse.c \
			   complementary1.c \
			   complementary2.c \
			   errors.c \
			   cleaning.c \
			   new_check_name.c \
			   new_check_comment.c \
			   ft_strndup.c \
			   check_args.c \
			   check_operation.c \
			   check_instructions.c \
			   check_instructions2.c \
			   ft_itoa_hex.c \
			   ft_lennum_hex.c \
			   ft_lennum.c \
			   create_label.c \
			   assembly.c \
			   translation.c \
			   magic_header_to_byte.c \
			   cycle.c \
			   instruction_to_byte.c \
			   arg_to_byte.c \
			   exec_to_byte.c \
			   ft_strjoin_se.c \
			   weight.c

OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o);
SRC_ASM = $(addprefix $(OBJDIR)/, $(SRC_ASM_NAME))
OBJ_ASM = $(addprefix $(OBJDIR)/, $(OBJ_ASM_NAME))

all: libft $(ASM)

$(ASM): $(OBJ_ASM)
	@gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/asm.h
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	@make -C $(LIBDIR)

clean:
	@make clean -C $(LIBDIR)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -Rf $(ASM)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include
