/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 15:37:28 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	*dir_type4(t_champ *champ, int value)
{
	unsigned char	*res;

	if (!(res = ft_memalloc(4)))
		ft_error(champ);
	res[3] = value & 255;
	res[2] = (value >> 8) & 255;
	res[1] = (value >> 16) & 255;
	res[0] = (value >> 24) & 255;
	return (res);
}

unsigned char	*dir_type2(t_champ *champ, int value)
{
	unsigned char	*res;

	if (!(res = ft_memalloc(2)))
		ft_error(champ);
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
		value = ft_atoi(str + 1);
	if (type == 2)
		return (dir_type2(champ, value));
	if (type == 4)
		return (dir_type4(champ, value));
	ft_error(champ);
	return (NULL);
}

unsigned char	*reg_to_byte(t_champ *champ, char *str)
{
	int				value;
	unsigned char	*res;

	value = ft_atoi(str + 1);
	if (!(res = ft_memalloc(1)))
		ft_error(champ);
	res[0] = value;
	return (res);
}

unsigned char	*indir_to_byte(t_champ *champ, char *str)
{
	int				value;
	unsigned char	*res;

	if (!(res = ft_memalloc(2)))
		ft_error(champ);
	if (str[0] == LABEL_CHAR)
		value = find_label(champ, str) - champ->all_weight;
	else
		value = ft_atoi(str);
	res[0] = (value >> 8) & 255;
	res[1] = value & 255;
	return (res);
}
