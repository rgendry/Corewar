/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/04 19:24:17 by rgendry          ###   ########.fr       */
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
		// if (str[0] == DIRECT_CHAR)
		// {
		// 	if (!(ft_strncmp(head->name, str + 2, (ft_strlen(str) - 2))))
		// 		return (head->place);
		// }
		// if (str[0] == LABEL_CHAR)
		// {
		// 	if (!(ft_strncmp(head->name, str + 1, (ft_strlen(str) - 1))))
		// 		return (head->place);
		// }
		head = head->next;
	}
	ft_error();
	return (0);
}

unsigned char	*dir_type4(int value)
{
	unsigned char	*res;

	if (!(res = ft_memalloc(4)))
		ft_error();
	res[3] = value & 255;
	res[2] = (value >> 8 ) & 255;
	res[1] = (value >> 16) & 255;
	res[0] = (value >> 24) & 255;
	return (res);
}

unsigned char	*dir_type2(int value)
{
	unsigned char	*res;

	if (!(res = ft_memalloc(2)))
		ft_error();
	res[1] = value & 255;
	res[0] = (value >> 8) & 255;
	return (res);
}

unsigned char	*dir_to_byte(t_champ *champ, char *str, int type)
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

unsigned char	*reg_to_byte(char *str)
{
	int				value;
	unsigned char	*res;

	value = ft_atoi(++str);
	if (!(res = ft_memalloc(1)))
		ft_error();
	res[0] = value;
	return (res);
}

unsigned char	*indir_to_byte(t_champ *champ, char *str)
{
	int				value;
	unsigned char	*res;

	if (!(res = ft_memalloc(2)))
		ft_error();
	if (str[0] == LABEL_CHAR)
		value = find_label(champ, str);
	else
		value = ft_atoi(str);
	res[0] = (value >> 8) & 255;
	res[1] = value & 255;
	return (res);
}
