/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:16 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_live(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	game->live++;
	take_args(game->arena, car, op);
	car->live = game->hook;
	if (car->args[0] < 0 && car->args[0] >= -(game->champs))
		game->last_alive = -car->args[0];
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | live %d\n", car->numb, car->args[0]);
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
