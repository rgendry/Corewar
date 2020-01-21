/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_to_byte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:46:38 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 20:35:24 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	operation_type(t_champ *champ, char *str)
{
	unsigned char	op;

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
		ft_error(champ);
	return (op);
}

unsigned char	arg_type(char **token, int label)
{
	int				increment;
	unsigned char	res;

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

void			dir_type(t_champ *champ, t_arg *arg, char *str, char type)
{
	if ((type >= 1 && type <= 8) || type == 13 || type == 16)
	{
		arg->weight = 4;
		arg->byte_code = dir_to_byte(champ, str, 4);
	}
	if ((type >= 9 && type <= 12) || type == 14 || type == 15)
	{
		arg->weight = 2;
		arg->byte_code = dir_to_byte(champ, str, 2);
	}
	return ;
}

t_arg			*arg_to_byte(t_champ *champ, char *str, char type)
{
	t_arg	*arg;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		ft_error(champ);
	if (check_arg_type(str) == 1)
	{
		arg->weight = 1;
		arg->byte_code = reg_to_byte(champ, str);
	}
	if (check_arg_type(str) == 2)
		dir_type(champ, arg, str, type);
	if (check_arg_type(str) == 3)
	{
		arg->weight = 2;
		arg->byte_code = indir_to_byte(champ, str);
	}
	return (arg);
}

t_instr			*instruction_to_byte(t_champ *champ, char **token, int label,
	t_instr *byte_code)
{
	if (label && !token[1])
		return (NULL);
	if (!(byte_code = (t_instr *)malloc(sizeof(t_instr))))
		ft_error(champ);
	byte_code->instr = operation_type(champ, token[0 + label]);
	byte_code->type = 0;
	byte_code->arg1 = NULL;
	byte_code->arg2 = NULL;
	byte_code->arg3 = NULL;
	if (byte_code->instr != 1 && byte_code->instr != 9 &&
		byte_code->instr != 12 && byte_code->instr != 15)
		byte_code->type = arg_type(token, label);
	if (!is_emptystr(token[1 + label]))
		byte_code->arg1 = arg_to_byte(champ, token[1 + label],
		byte_code->instr);
	if (!is_emptystr(token[2 + label]))
		byte_code->arg2 = arg_to_byte(champ, token[2 + label],
		byte_code->instr);
	if (!is_emptystr(token[3 + label]))
		byte_code->arg3 = arg_to_byte(champ, token[3 + label],
		byte_code->instr);
	byte_code->next = NULL;
	ft_count_current_weight(byte_code);
	return (byte_code);
}
