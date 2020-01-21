/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_sup3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:28:54 by crenly-b          #+#    #+#             */
/*   Updated: 2019/12/14 20:41:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_old_error(char **str)
{
	ft_printf("Incorrect input = %s.\n", *str);
	exit(-1);
}

int			ft_check_dump(char ***str, int number, int *i)
{
	if (number == 2 || number == 4 || number == 8
		|| number == 16 || number == 30)
		return (number);
	else
		ft_old_error(&(*str)[*i]);
	return (0);
}
