/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_sup2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:06:15 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/19 15:32:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_sort_players_sup1(t_val *val)
{
	int i;
	int j;

	i = 0;
	if (val->amount_of_players == 0)
		ft_error("No players.");
	if (val->amount_of_players > MAX_PLAYERS)
		ft_error("Too much players.");
	while (i < MAX_PLAYERS)
	{
		if (val->players[i][0] == 0)
		{
			j = i;
			while (j < MAX_PLAYERS && val->players[j][0] == 0)
				j++;
			if (j < MAX_PLAYERS && val->players[j][0] != 0)
			{
				ft_strcat(val->players[i], val->players[j]);
				j++;
			}
		}
		i++;
	}
}

void			ft_sort_players(t_val *val)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MAX_PLAYERS)
	{
		if (val->players[i][0] == 0)
		{
			while (j < val->amount_of_players)
			{
				if (val->temp_players[j][0] != 0)
				{
					ft_strcat(val->players[i], val->temp_players[j]);
					j++;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	ft_sort_players_sup1(val);
}

void			ft_analyse_players(t_val *val, t_champ *champ, int *game_champs)
{
	int i;
	int fd;

	i = 0;
	while (i < val->amount_of_players)
	{
		if ((fd = open(val->players[i], O_RDWR)) < 2)
		{
			ft_printf("%d\n", fd);
			ft_error("Bad file.\n");
		}
		init_champ(fd, &(champ[i]));
		i++;
	}
	(*game_champs) = val->amount_of_players;
}

int				ft_if_aff_flag(char ***str, t_val *val, int *i)
{
	if (ft_strequ((*str)[*i], "-a") == 1 || val->value_param == 30)
	{
		if (val->flag_aff_flag == 0 || val->value_param == 30)
		{
			val->flag_aff_flag = 1;
			return (1);
		}
		else
			ft_error("Incorrect input aff flag \"-a\".");
	}
	return (0);
}
