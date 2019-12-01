/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:54:11 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/01 18:55:00 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i > 1 && str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

t_label	*create_label(char	*data)
{
	t_label	*new;

	if (!(new = (t_label *)malloc(sizeof(t_label))))
		ft_error();
	new->name = ft_strdup(data);
	new->place = 0;
	new->next = NULL;
	return (new);
}

int		add_label(t_label **head, t_label *new)
{
	t_label	*next;

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
	return (1);
}
