/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:51 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:52 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_sti(t_carriage *car, t_val *val)
{
	if (val->value_param == 4 || val->value_param == 30)
	{
		ft_printf("P %4d | sti r%d %d %d\n",
			car->numb, car->args[0], car->args[1], car->args[2]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			car->args[1], car->args[2], car->args[1] + car->args[2],
			(car->pc + idx_mod(car->args[1] + car->args[2])));
	}
}

unsigned int	op_sti(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int			i;

	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	i = 0;
	while (++i < 3)
	{
		if (car->targ[i] == T_REG)
			car->args[i] = car->reg[car->args[i]];
		else if (car->targ[i] == T_IND)
			car->args[i] = bytes_to_int(game->arena,
				(car->pc + idx_mod(car->args[i])) % MEM_SIZE, REG_SIZE);
	}
	int_to_bytes(car->reg[car->args[0]], game->arena,
		car->pc + idx_mod(car->args[1] + car->args[2]), REG_SIZE);
	print_sti(car, val);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
