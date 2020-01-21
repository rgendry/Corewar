/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:36 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:37 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_or(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int			i;
	uint32_t	or;

	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	i = -1;
	while (++i < 2)
	{
		if (car->targ[i] == T_REG)
			car->args[i] = car->reg[car->args[i]];
		else if (car->targ[i] == T_IND)
			car->args[i] = bytes_to_int(game->arena,
			(car->pc + idx_mod(car->args[i])) % MEM_SIZE, REG_SIZE);
	}
	or = car->args[0] | car->args[1];
	car->carry = 1 ? or == 0 : 0;
	car->reg[car->args[2]] = or;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | or %d %d r%d\n",
			car->numb, car->args[0], car->args[1], car->args[2]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
