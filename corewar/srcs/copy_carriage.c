/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:25:20 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 18:25:21 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carriage	copy_carriage(t_carriage *car, t_game *game)
{
	t_carriage	new_car;
	int			i;

	i = 0;
	while (++i < REG_NUMBER + 1)
		new_car.reg[i] = car->reg[i];
	new_car.carry = car->carry;
	new_car.live = car->live;
	new_car.hookbefexe = 0;
	game->count_carriage++;
	new_car.numb = game->count_carriage;
	return (new_car);
}
