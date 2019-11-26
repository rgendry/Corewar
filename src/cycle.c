/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/26 13:41:53 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	add_instr(t_instr **head, t_instr *new)
{
	t_instr	*next;

	if (!new)
		ft_error();
	next = *head;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = new;
	}
	else
		*head = new;
	return (new->weight);
}

void	ft_cycle(t_champ *champ)
{
    int label;
    t_tokens    *head;

    head = champ->string;
    while (head)
    {
        label = 0;
        if (is_label(head->token[0]))
            label = 1;
        add_instr(&champ->byte_code, instruction_to_byte(champ, head->token, label)); // сега тут
        head = head->next;
    }
}
