/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:57 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:59 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_sub(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t	sub;

	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	sub = car->reg[car->args[0]] - car->reg[car->args[1]];
	if (sub == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->reg[car->args[2]] = sub;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | sub r%d r%d r%d\n", car->numb,
				car->args[0], car->args[1], car->args[2]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
