/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 01:48:55 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/18 16:27:26 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_one_step(t_val *val, t_game *game, t_carriage *car)
{
	unsigned int i;
	unsigned int step;

	step = car->new_pc - car->pc;
	i = 0;
	if (val->value_param == 16 || val->value_param == 30)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", step, car->pc, car->new_pc);
		while (i < step)
		{
			ft_printf("%.2x ", game->arena[(car->pc + i) % MEM_SIZE]);
			i++;
		}
		ft_printf("\n");
	}
}
