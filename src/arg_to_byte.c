/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/01 18:52:30 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_label(t_champ *champ, char *str)
{
	t_label	*head;

	head = champ->labels;
	while (head)
	{
		if (str[0] == DIRECT_CHAR)
		{
			if (!(ft_strncmp(str + 2, head->name, (ft_strlen(head->name) - 1))))
				return (head->place);
		}
		if (str[0] == LABEL_CHAR)
		{
			if (!(ft_strncmp(++str, head->name, (ft_strlen(head->name) - 1))))
				return (head->place);
		}
		head = head->next;
	}
	ft_error();
	return (0);
}

char	*dir_type4(int value)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 4)))
		ft_error();
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[3] = value;
	return (res);
}

char	*dir_type2(int value)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		ft_error();
	if (value < 0)
		res[0] = -1;
	else
		res[0] = 0;
	res[1] = value;
	return (res);
}

char	*dir_to_byte(t_champ *champ, char *str, int type)
{
	int		value;

	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
		value = find_label(champ, str) - champ->all_weight;
	else
		value = ft_atoi(++str);
	if (type == 2)
		return (dir_type2(value));
	if (type == 4)
		return (dir_type4(value));
	ft_error();
	return (NULL);
}

char	*reg_to_byte(char *str)
{
	int		value;
	char	*res;

	value = ft_atoi(++str);
	if (!(res = (char *) malloc(sizeof(char))))
		ft_error();
	res[0] = value;
	return (res);
}

char	*indir_to_byte(t_champ *champ, char *str)
{
	int		value;
	char	*res;

	if (!(res = (char *)malloc (sizeof(char) * 2)))
		ft_error();
	if (str[0] == LABEL_CHAR)
		value = find_label(champ, str); //champ->all_weight - find_label(champ, str);
	else
		value = ft_atoi(str);
	res[0] = 0;
	res[1] = value;
	return (res);
}
