/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_olya_init_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:22:20 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/18 14:44:39 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		del_carriage(t_game *game, t_val *val,
						t_list **list, t_list **pr_list)
{
	t_carriage *car;

	car = (t_carriage*)((*list)->content);
	if (val->value_param == 30)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			car->numb, car->live > 0 ? game->hook - car->live : game->hook,
														game->cycles_to_die);
	free(car);
	if (game->carriages == *list)
	{
		game->carriages = (*list)->next;
		ft_memdel((void**)list);
		(*list) = game->carriages;
	}
	else
	{
		(*pr_list)->next = (*list)->next;
		ft_memdel((void**)list);
		*list = (*pr_list)->next;
	}
}

static int		revision(t_game *game, t_val *val)
{
	t_list		*list;
	t_list		*pr_list;

	game->checks++;
	list = game->carriages;
	while (list != NULL)
	{
		if (game->hook - ((t_carriage*)(list->content))->live
									>= game->cycles_to_die)
			del_carriage(game, val, &list, &pr_list);
		else
		{
			pr_list = list;
			list = list->next;
		}
	}
	if (game->live >= NBR_LIVE || game->checks >= MAX_CHECKS)
	{
		game->cycles_to_die -= CYCLE_DELTA;
		if (val->value_param == 30)
			ft_printf("Cycle to die is now %d\n", game->cycles_to_die);
		game->checks = 0;
	}
	game->live = 0;
	return (game->cycles_to_die);
}

static void		carriage_cycle(t_list *list, t_val *val, t_game *game)
{
	t_carriage *car;

	while (list != NULL)
	{
		car = (t_carriage*)(list->content);
		if (car->hookbefexe == 0)
			cycles_before_execution(car, game->arena[(car->pc) % MEM_SIZE]);
		if (car->hookbefexe > 0)
			car->hookbefexe--;
		if (car->hookbefexe == 0)
			operation(val, game, car, car->operation);
		list = list->next;
	}
}

void			start_game(t_val *val, t_game *game, int dump_value)
{
	t_list		*list;
	int			left_to_check;
	t_champ		champ;

	left_to_check = game->cycles_to_die;
	while (game->carriages != NULL)
	{
		if ((val->value_param == 2 || val->value_param == 30)
									&& val->dump_value != 0)
			ft_printf("It is now cycle %d\n", game->hook);
		list = game->carriages;
		carriage_cycle(list, val, game);
		left_to_check--;
		if (left_to_check <= 0)
			left_to_check = revision(game, val);
		if (game->hook == dump_value)
		{
			show_arena(game);
			exit(0);
		}
		game->hook++;
	}
	champ = game->champ[game->last_alive - 1];
	ft_printf("Contestant %d, \"%s\", has won !\n",
						game->last_alive, champ.name);
}
