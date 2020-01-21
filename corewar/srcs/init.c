/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:58:33 by bharmund          #+#    #+#             */
/*   Updated: 2020/01/20 16:58:36 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_game_struct(t_game *game, int amount_of_players)
{
	int	bite;
	int	i;
	int	j;

	ft_bzero(game->arena, MEM_SIZE);
	i = -1;
	while (++i < amount_of_players)
	{
		j = -1;
		bite = MEM_SIZE / amount_of_players * i;
		while (++j < (game->champ[i]).exec_code_size &&
			bite < MEM_SIZE / amount_of_players * (i + 1))
		{
			game->arena[bite] = (game->champ[i]).exec_code[j];
			bite++;
		}
	}
	game->last_alive = amount_of_players;
	game->hook = 1;
	game->live = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks = 0;
	game->carriages = NULL;
	game->champs = amount_of_players;
	game->count_carriage = amount_of_players;
}

void	init_game(t_game *game, int amount_of_players)
{
	int			i;
	t_carriage	new_carriage;
	t_list		*new;

	init_game_struct(game, amount_of_players);
	i = -1;
	while (++i < REG_NUMBER + 1)
		new_carriage.reg[i] = 0;
	new_carriage.live = -1;
	new_carriage.carry = 0;
	new_carriage.hookbefexe = 0;
	i = 0;
	while (++i <= amount_of_players)
	{
		new_carriage.numb = i;
		new_carriage.pc = (MEM_SIZE / amount_of_players) * (i - 1);
		new_carriage.reg[1] = -i;
		if (!(new = ft_lstnew((void*)&new_carriage, sizeof(t_carriage))))
			ft_error("memor :(");
		ft_lstadd(&(game->carriages), new);
	}
}
