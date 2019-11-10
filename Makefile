# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 18:20:25 by rgendry           #+#    #+#              #
#    Updated: 2019/11/06 16:42:03 by ubartemi         ###   ########.fr        #
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
			   complementary.c \
			   check_name.c \
			   check_comment.c \
			   ft_strndup.c \
			   comment.c

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
