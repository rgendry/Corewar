/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:44 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:45 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_st(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	if (car->targ[1] == T_REG)
		car->reg[car->args[1]] = car->reg[car->args[0]];
	else
		int_to_bytes(car->reg[car->args[0]], game->arena,
		car->pc + idx_mod(car->args[1]), REG_SIZE);
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | st r%d %d\n", car->numb, car->args[0], car->args[1]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
