/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:34:08 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 20:36:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_count_current_weight(t_instr *byte_code)
{
	byte_code->weight = 0;
	if (byte_code->instr)
		byte_code->weight++;
	if (byte_code->type)
		byte_code->weight++;
	if (byte_code->arg1)
		byte_code->weight += byte_code->arg1->weight;
	if (byte_code->arg2)
		byte_code->weight += byte_code->arg2->weight;
	if (byte_code->arg3)
		byte_code->weight += byte_code->arg3->weight;
}

int		ft_count_weight(t_champ *champ, char **token, int label)
{
	int	i;
	int	type;
	int	weight;

	i = 1;
	weight = 1;
	type = operation_type(champ, token[0 + label]);
	if (type != 1 && type != 9 && type != 12 && type != 15)
		weight++;
	while (token[i + label])
	{
		weight += ft_arg_weight(token[i + label], type);
		i++;
	}
	return (weight);
}
