/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/26 14:02:33 by rgendry          ###   ########.fr       */
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

char	*dir_to_byte(t_champ *champ, char *str, int type)
{
	int		i;
	int		value;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * 5)))
		ft_error();
	if (str[0] == '%' && str[1] == ':')
		value = find_label(champ, str);
	else
		value = ft_atoi(++str);
	while (i < 5)
	{
		res[i] = 0;
		if (type == 2 && i == 1)
			res[i] = value;
		if (type == 4 && i == 3)
			res[i] = value;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*reg_to_byte(char *str)
{
	int		i;
	int		value;
	char	*res;

	i = 0;
	value = ft_atoi(++str);
	if (!(res = (char *) malloc(sizeof(char) * 5)))
		ft_error();
	res[i++] = value;
	while (i < 5)
	{
		res[i] = 0;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*indir_to_byte(t_champ *champ, char *str)
{
	int		i;
	int		value;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc (sizeof(char) * 5)))
		ft_error();
	if (str[0] == ':')
		value = champ->all_weight - find_label(champ, str);
	else
		value = ft_atoi(str);
	while (i < 5)
	{
		res[i] = 0;
		if (i == 1)
			res[i] = value;
		i++;
	}
	res[i] = '\0';
	return (res);
}
