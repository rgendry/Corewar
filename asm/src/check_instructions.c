/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:21:24 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/15 18:25:01 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_type2(char **token, int label)
{
	if (arr_len(token) != (2 + label))
		return (0);
	if (token[label + 1] && check_arg_type(token[label + 1]) == 2)
		return (3);
	return (0);
}

int	check_type3(char **token, int label)
{
	if (arr_len(token) != (3 + label))
		return (0);
	if (token[label + 1] && (check_arg_type(token[label + 1]) == 2 ||
		check_arg_type(token[label + 1]) == 3) && token[label + 2] &&
		check_arg_type(token[label + 2]) == 1)
		return (3);
	return (0);
}

int	check_type4(char **token, int label)
{
	if (arr_len(token) != (3 + label))
		return (0);
	if (token[label + 1] && check_arg_type(token[label + 1]) == 1 &&
		token[label + 2] && (check_arg_type(token[label + 2]) == 3 ||
		check_arg_type(token[label + 2]) == 1))
		return (3);
	return (0);
}

int	check_type5(char **token, int label)
{
	if (arr_len(token) != (4 + label))
		return (0);
	if (token[label + 1] && check_arg_type(token[label + 1]) == 1 &&
		token[label + 2] && check_arg_type(token[label + 2]) == 1 &&
		token[label + 2] && check_arg_type(token[label + 3]) == 1)
		return (3);
	return (0);
}

int	check_type6(char **token, int label)
{
	if (arr_len(token) != (4 + label))
		return (0);
	if (token[label + 1] && check_arg_type(token[label + 1]) != 0 &&
		token[label + 2] && check_arg_type(token[label + 2]) != 0 &&
		token[label + 3] && check_arg_type(token[label + 3]) == 1)
		return (3);
	return (0);
}
