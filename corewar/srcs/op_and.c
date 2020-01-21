/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:47:35 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 17:47:37 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_and(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int			i;
	uint32_t	and;

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
	and = car->args[0] & car->args[1];
	car->carry = 1 ? and == 0 : 0;
	car->reg[car->args[2]] = and;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | and %d %d r%d\n",
			car->numb, car->args[0], car->args[1], car->args[2]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
