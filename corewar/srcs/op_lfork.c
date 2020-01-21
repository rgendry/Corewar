/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:07 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:26:08 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	op_lfork(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	t_carriage	new_car;
	t_list		*new;

	take_args(game->arena, car, op);
	new_car = copy_carriage(car, game);
	new_car.pc = (car->pc + car->args[0]) % MEM_SIZE;
	if (!(new = ft_lstnew((void*)&new_car, sizeof(t_carriage))))
		ft_error("memor :(");
	ft_lstadd(&(game->carriages), new);
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | lfork %d (%d)\n",
			car->numb, car->args[0], (car->pc + car->args[0]));
	print_one_step(val, game, car);
	return ((car->new_pc) % MEM_SIZE);
}
