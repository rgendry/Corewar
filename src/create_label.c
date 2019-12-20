/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:54:11 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 15:48:29 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_label(t_champ *champ, char *str)
{
	t_label	*head;
	char	*name;

	head = champ->labels;
	if (str[0] == DIRECT_CHAR)
		name = ft_strjoin(str + 2, ":");
	if (str[0] == LABEL_CHAR)
		name = ft_strjoin(str + 1, ":");
	while (head)
	{
		if (!(ft_strcmp(head->name, name)))
		{
			ft_strdel(&name);
			return (head->place);
		}
		head = head->next;
	}
	ft_error(champ);
	return (0);
}

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

void	check_sym(t_champ *champ, char *data)
{
	int i;

	i = 0;
	while (data[i] != ':')
	{
		if (!(ft_strchr(LABEL_CHARS, data[i])))
			ft_lex_error(champ);
		i++;
	}
	i++;
	if (data[i])
		ft_lex_error(champ);
}

t_label	*create_label(t_champ *champ, char *data)
{
	t_label	*new;

	check_sym(champ, data);
	if (!(new = (t_label *)malloc(sizeof(t_label))))
		exit(EXIT_FAILURE);
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
