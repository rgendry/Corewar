/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:23:37 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:23:41 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_add(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t	sum;

	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	sum = car->reg[car->args[0]] + car->reg[car->args[1]];
	if (sum == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->reg[car->args[2]] = sum;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | add r%d r%d r%d\n",
		car->numb, car->args[0], car->args[1], car->args[2]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
