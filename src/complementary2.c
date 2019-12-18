/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:38:45 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 20:57:29 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_numln(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i + 1);
	}
	return (i);
}

void	ft_too_long_name(t_champ *champ)
{
	ft_printf("Champion name too long (Max length %d)\n", 128);
	ft_clear_everything(champ);
	exit(EXIT_FAILURE);
}

void	ft_too_long_com(t_champ *champ)
{
	ft_printf("Champion comment too long (Max length %d)\n", COMMENT_LENGTH);
	ft_clear_everything(champ);
	exit(EXIT_FAILURE);
}

void	free_arr(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	ft_create_com(t_champ *champ)
{
	champ->com->comment = ft_memalloc(2048);
	if (!(champ->com->comment))
		ft_error(champ);
}
