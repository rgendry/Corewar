/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:27:11 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:27:20 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_zjmp(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	take_args(game->arena, car, op);
	if (car->carry == 1)
	{
		car->new_pc = ((car->pc + idx_mod(car->args[0]))) % MEM_SIZE;
		if (val->value_param == 4 || val->value_param == 30)
			ft_printf("P %4d | zjmp %d OK\n", car->numb, car->args[0]);
		return ((car->new_pc));
	}
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | zjmp %d FAILED\n", car->numb, car->args[0]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
