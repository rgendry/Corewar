/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/25 16:27:07 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_instr(t_instr **head, t_instr *new)
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
}

void	ft_cycle(t_champ *champ, int i)
{
	t_instr	*byte_code;
	char	*newstr;
	char	**token;

    while (champ->file[i])
    {
        newstr = spaces(champ->file[i], 0, 0);
		token = ft_strsplit(newstr, ',');
		add_instr(&byte_code, instruction_to_byte(token, check_label(token[0])));
		i++;
    }
}
