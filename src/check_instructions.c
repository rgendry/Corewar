/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:21:24 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/17 18:52:20 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_type2(char **token, int label)
{
	if (check_arg_type(token[label + 1]) == 2)
		return (2);
	return (0);
}

int	check_type3(char **token, int label)
{
	if ((check_arg_type(token[label + 1]) == 2 ||
		check_arg_type(token[label + 1]) == 3) &&
		check_arg_type(token[label + 2]) == 1)
		return (3);
	return (0);
}

int	check_type4(char **token, int label)
{
	if (check_arg_type(token[label + 1]) == 1 &&
		(check_arg_type(token[label + 2]) == 3 ||
		check_arg_type(token[label + 2]) == 1))
		return (4);
	return (0);
}

int	check_type5(char **token, int label)
{
	if (check_arg_type(token[label + 1]) == 1 &&
		check_arg_type(token[label + 2]) == 1 &&
		check_arg_type(token[label + 3]) == 1)
		return (5);
	return (0);
}

int	check_type6(char **token, int label)
{
	if (check_arg_type(token[label + 1]) != 0 &&
		check_arg_type(token[label + 2]) != 0 &&
		check_arg_type(token[label + 3]) == 1)
		return (6);
	return (0);
}
