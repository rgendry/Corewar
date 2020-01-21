/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:34:42 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 18:34:47 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				idx_mod(int pc)
{
	if (pc > 0)
		return (pc % IDX_MOD);
	while (pc < 0 && pc <= -IDX_MOD)
		pc += IDX_MOD;
	return (pc);
}

int				shift_arg(uint8_t t_array[], int size, int dir_size)
{
	int	shift;
	int	i;

	shift = 0;
	i = 0;
	while (i < size)
	{
		if (t_array[i] == T_REG)
			shift++;
		else if (t_array[i] == T_DIR)
			shift += dir_size;
		else if (t_array[i] == T_IND)
			shift += IND_SIZE;
		i++;
	}
	return (shift);
}

static int		car_args(uint8_t arena[], t_carriage *car, t_op op)
{
	int				i;
	int				size_arg;
	unsigned int	pc;

	pc = (car->pc + op.tcode + LEN_ARGS_CODE) % MEM_SIZE;
	i = -1;
	while (++i < op.count_args)
	{
		if (car->targ[i] == T_DIR)
			size_arg = op.dir_size;
		else if (car->targ[i] == T_REG)
			size_arg = 1;
		else if (car->targ[i] == T_IND)
			size_arg = IND_SIZE;
		car->args[i] = bytes_to_int(arena, pc, size_arg);
		if (car->targ[i] == T_REG && (car->args[i] < 1 || car->args[i] > 16))
			return (-1);
		pc = (pc + size_arg) % MEM_SIZE;
	}
	return (0);
}

int				take_args(uint8_t arena[], t_carriage *car, t_op op)
{
	int i;

	if (op.tcode)
		take_targ(arena[(car->pc + 1) % MEM_SIZE], car->targ, op.count_args);
	i = -1;
	while (op.tcode == 0 && ++i < op.count_args)
		car->targ[i] = op.targ[i];
	car->new_pc = car->pc + LEN_ARGS_CODE + op.tcode +
		shift_arg(car->targ, op.count_args, op.dir_size);
	i = -1;
	while (++i < op.count_args)
	{
		if ((op.targ[i] & car->targ[i]) == 0)
			return (-1);
	}
	if (car_args(arena, car, op) == -1)
		return (-1);
	return (0);
}

void			take_targ(uint8_t byte, uint8_t targ[], int size)
{
	int		i;
	uint8_t	type_code;

	i = 0;
	while (i < size)
	{
		type_code = (byte & 0xc0) >> 6;
		if (type_code == REG_CODE)
			targ[i] = T_REG;
		else if (type_code == DIR_CODE)
			targ[i] = T_DIR;
		else if (type_code == IND_CODE)
			targ[i] = T_IND;
		else
			targ[i] = T_LAB;
		byte = byte << 2;
		i++;
	}
}
