/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:40:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/21 16:11:48 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_type7(char **token, int label)
{
	if (check_arg_type(token[label + 1]) != 0 &&
		(check_arg_type(token[label + 2]) == 1 ||
		check_arg_type(token[label + 2]) == 2) &&
		check_arg_type(token[label + 3]) == 1)
		return (3);
	return (0);
}

int	check_type8(char **token, int label)
{
	if (check_arg_type(token[label + 1]) == 1 &&
		check_arg_type(token[label + 2]) != 0 &&
		(check_arg_type(token[label + 3]) == 1 ||
		check_arg_type(token[label + 3]) == 2))
		return (3);
	return (0);
}

int	check_type9(char **token, int label)
{
	if (check_arg_type(token[label + 1]) == 1)
		return (3);
	return (0);
}
