/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/27 17:14:21 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_label(t_champ *champ, char *str) //  Тут надо разобраться, по идее должно возвращаться не само число,
{												// а разница между текущим положением и этим числом
	while (champ->labels)						// но наверное лучше это считать не в этой функции :)
	{
		if (str[0] == '%')
		{
			if (!(ft_strncmp(str + 2, champ->labels->name, ft_strlen(champ->labels->name - 1))))
				return (champ->labels->place);
		}
		if (str[0] == ':')
		{
			if (!(ft_strncmp(++str, champ->labels->name, ft_strlen(champ->labels->name - 1))))
				return (champ->labels->place);
		}
		champ->labels = champ->labels->next;
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
	res[0] = 0;
	res[0] = 0;
	res[4] = value;
	return (res);
}

char	*dir_type2(int value)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		ft_error();
	res[0] = 0;
	res[1] = value;
	return (res);
}

char	*dir_to_byte(t_champ *champ, char *str, int type)
{
	int		value;

	if (str[0] == '%' && str[1] == ':')
		value = find_label(champ, str);
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
	if (str[0] == ':')
		value = champ->all_weight - find_label(champ, str);
	else
		value = ft_atoi(str);
	res[0] = 0;
	res[1] = value;
	return (res);
}
