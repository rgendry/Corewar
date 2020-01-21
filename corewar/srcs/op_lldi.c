/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:28 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:31 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_lldi(t_carriage *car, t_val *val)
{
	if (val->value_param == 4 || val->value_param == 30)
	{
		ft_printf("P %4d | lldi %d %d r%d\n",
			car->numb, car->args[0], car->args[1], car->args[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				car->args[0], car->args[1], car->args[0] + car->args[1],
					car->pc + car->args[0] + car->args[1]);
	}
}

unsigned int	op_lldi(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int			i;

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
	car->reg[car->args[2]] = bytes_to_int(game->arena,
				(car->pc + car->args[0] + car->args[1]) % MEM_SIZE, REG_SIZE);
	car->carry = 1 ? car->args[0] == 0 : 0;
	print_lldi(car, val);
	print_one_step(val, game, car);
	return (car->new_pc);
}
