/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_to_byte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:46:38 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/25 15:47:48 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	operation_type(char *str)
{
	char	op;

	op = 0;
	!ft_strcmp(str, "live") ? op = 1 : op;
	!ft_strcmp(str, "ld") ? op = 2 : op;
	!ft_strcmp(str, "st") ? op = 3 : op;
	!ft_strcmp(str, "add") ? op = 4 : op;
	!ft_strcmp(str, "sub") ? op = 5 : op;
	!ft_strcmp(str, "and") ? op = 6 : op;
	!ft_strcmp(str, "or") ? op = 7 : op;
	!ft_strcmp(str, "xor") ? op = 8 : op;
	!ft_strcmp(str, "zjmp") ? op = 9 : op;
	!ft_strcmp(str, "ldi") ? op = 10 : op;
	!ft_strcmp(str, "sti") ? op = 11 : op;
	!ft_strcmp(str, "fork") ? op = 12 : op;
	!ft_strcmp(str, "lld") ? op = 13 : op;
	!ft_strcmp(str, "lldi") ? op = 14 : op;
	!ft_strcmp(str, "lfork") ? op = 15 : op;
	!ft_strcmp(str, "aff") ? op = 16 : op;
	if (op == 0)
		ft_error();
	return (op);
}

char	arg_type(char **token, int label)
{
	int		increment;
	char	res;

	res = 0;
	if (token[1 + label])
	{
		increment = check_arg_type(token[1 + label]);
		res += 64 * increment;
	}
	if (token[2 + label])
	{
		increment = check_arg_type(token[2 + label]);
		res += 16 * increment;
	}
	if (token[3 + label])
	{
		increment = check_arg_type(token[3 + label]);
		res += 4 * increment;
	}
	return (res);
}

char	*arg_to_byte(char *str)
{
	char	arg[4];
	return (arg);
}

void	instruction_to_byte(char **token, int label)
{
	t_instr	*byte_code;

	if (!(byte_code = (t_instr *) malloc (sizeof(t_instr))))
		ft_error();
	byte_code->instr = operation_type(token[0 + label]);
	byte_code->type = 0;
	if (byte_code->instr != 1 && byte_code->instr != 9 &&
		byte_code->instr != 12 && byte_code->instr != 15)
		byte_code->type = arg_type(token, label);
	byte_code->arg1 = arg_to_byte(token[1 + label]);
	if (token[2 + label])
		byte_code->arg2 = arg_to_byte(token[2 + label]);
	if (token[3 + label])
		byte_code->arg2 = arg_to_byte(token[3 + label]);
	byte_code->next = NULL;
}
