/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2020/01/19 16:45:01 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		add_instr(t_instr **head, t_instr *new)
{
	t_instr	*next;

	if (!new)
		return (0);
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
	int			label;
	t_tokens	*head;

	head = champ->string;
	champ->all_weight = 0;
	while (head)
	{
		label = 0;
		if (is_label(head->token[0]))
			label = 1;
		champ->all_weight += add_instr(&champ->byte_code,
				instruction_to_byte(champ, head->token, label, NULL));
		head = head->next;
	}
}

void	del_label(t_label **labels, char **token)
{
	t_label **head;

	if (!is_label(token[0]))
		return ;
	head = labels;
	while (*head && (*head)->next)
		*head = (*head)->next;
	free((*head)->name);
	free(*head);
	*head = NULL;
}
