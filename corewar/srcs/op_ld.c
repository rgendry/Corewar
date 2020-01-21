/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:45 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:25:50 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_ld(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	if (car->targ[0] == T_IND)
		car->args[0] = bytes_to_int(game->arena,
			(car->pc + idx_mod(car->args[0])) % MEM_SIZE, REG_SIZE);
	if (car->args[0] == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->reg[car->args[1]] = car->args[0];
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | ld %d r%d\n", car->numb, car->args[0], car->args[1]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
