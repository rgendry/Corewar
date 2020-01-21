/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:54:43 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 17:54:44 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycles_before_execution(t_carriage *car, uint8_t oper)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (g_tab[i].code == oper)
		{
			car->hookbefexe = g_tab[i].wait_cycles;
			break ;
		}
		i++;
	}
	if (i == 16)
		car->hookbefexe = 0;
	car->operation = oper;
}

void	addition_operation(t_val *val, t_game *game,
			t_carriage *car, uint8_t operation)
{
	if (operation == 0x09)
		car->pc = op_zjmp(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0a)
		car->pc = op_ldi(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0b)
		car->pc = op_sti(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0c)
		car->pc = op_fork(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0d)
		car->pc = op_lld(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0e)
		car->pc = op_lldi(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x0f)
		car->pc = op_lfork(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x10)
		car->pc = op_aff(val, game, car, g_tab[operation - 1]);
	else
		car->pc = (car->pc + 1) % MEM_SIZE;
}

void	operation(t_val *val, t_game *game, t_carriage *car, uint8_t operation)
{
	if (operation == 0x01)
		car->pc = op_live(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x02)
		car->pc = op_ld(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x03)
		car->pc = op_st(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x04)
		car->pc = op_add(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x05)
		car->pc = op_sub(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x06)
		car->pc = op_and(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x07)
		car->pc = op_or(val, game, car, g_tab[operation - 1]);
	else if (operation == 0x08)
		car->pc = op_xor(val, game, car, g_tab[operation - 1]);
	else
		addition_operation(val, game, car, operation);
}
