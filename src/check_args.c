/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:30:50 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/01 18:49:30 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_reg(char *str)
{
	str++;
	if (ft_atoi(str) >= 1 && ft_atoi(str) <= 16)
		return (1);
	return (0);
}

int		check_dir(char *str)
{
	str++;
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (!*str || *str == LABEL_CHAR)
		return (2);
	return (0);
}

int		check_indir(char *str)
{
	if (*str == LABEL_CHAR)
		return (3);
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (!*str)
		return (3);
	return (0);
}

int		check_arg_type(char *str)
{
	if (!str)
		ft_error();
	if (*str == 'r')
		return (check_reg(str));
	if (*str == DIRECT_CHAR)
		return (check_dir(str));
	return (check_indir(str));
}
