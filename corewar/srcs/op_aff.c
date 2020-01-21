/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:24:25 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:24:36 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_aff(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	if (take_args(game->arena, car, op) == -1)
	{
		print_one_step(val, game, car);
		return (car->new_pc % MEM_SIZE);
	}
	if (val->flag_aff_flag == 1 || val->value_param == 30)
		ft_printf("Aff: %c\n", (char)((car->reg[car->args[0]]) % 256));
	print_one_step(val, game, car);
	return (car->new_pc % MEM_SIZE);
}
