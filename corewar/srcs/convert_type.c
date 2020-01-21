/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:26:20 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 18:26:23 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	int_to_bytes(int numb, __uint8_t arena[], int pc, int size)
{
	void *p;

	while (pc < 0)
		pc += MEM_SIZE;
	p = &numb;
	if (size == 4)
	{
		arena[pc % MEM_SIZE] = *(uint8_t*)(p + 3);
		arena[(pc + 1) % MEM_SIZE] = *(uint8_t*)(p + 2);
		arena[(pc + 2) % MEM_SIZE] = *(uint8_t*)(p + 1);
		arena[(pc + 3) % MEM_SIZE] = *(uint8_t*)(p);
	}
	else
		ft_error("ERROR IN INT_TO_BYTE\n");
}

int		bytes_to_int(uint8_t arena[], int pc, int size)
{
	int			numb;
	void		*p;
	int16_t		double_byte;

	numb = 0;
	if (size == 1)
		numb = arena[pc % MEM_SIZE];
	else if (size == 2)
	{
		p = &double_byte;
		*(int8_t*)(p + 1) = arena[pc % MEM_SIZE];
		*(int8_t*)p = arena[(pc + 1) % MEM_SIZE];
		numb = double_byte;
	}
	else if (size == 4)
	{
		p = &numb;
		*(int8_t*)(p + 3) = arena[pc % MEM_SIZE];
		*(int8_t*)(p + 2) = arena[(pc + 1) % MEM_SIZE];
		*(int8_t*)(p + 1) = arena[(pc + 2) % MEM_SIZE];
		*(int8_t*)(p) = arena[(pc + 3) % MEM_SIZE];
	}
	else
		ft_error("bad byte\n");
	return (numb);
}
