/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 20:36:51 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_arg_weight(char *str, int type)
{
	if (is_comment(str))
		return (0);
	if (check_arg_type(str) == 1)
		return (1);
	if (check_arg_type(str) == 2)
	{
		if ((type >= 1 && type <= 8) || type == 13 || type == 16)
			return (4);
		if ((type >= 9 && type <= 12) || type == 14 || type == 15)
			return (2);
	}
	if (check_arg_type(str) == 3)
		return (2);
	return (0);
}

void	set_label(t_champ *champ, char *str, int place)
{
	t_label	*head;

	head = champ->labels;
	while (head)
	{
		if (!(ft_strcmp(str, head->name)))
		{
			head->place = place;
			return ;
		}
		head = head->next;
	}
	ft_error(champ);
}

void	ft_counter_weight(t_champ *champ)
{
	int			label;
	t_tokens	*head;

	label = 0;
	head = champ->string;
	while (head)
	{
		label = 0;
		if (is_label(head->token[0]))
		{
			set_label(champ, head->token[0], champ->all_weight);
			label = 1;
		}
		if (head->token[0 + label] && !is_comment(head->token[0 + label]))
			champ->all_weight += ft_count_weight(champ, head->token, label);
		head = head->next;
	}
}

void	ft_make_exec_size(t_champ *champ)
{
	int	shift;
	int	j;

	shift = 0;
	j = 3;
	if (!(champ->exec_size = ft_memalloc(4)))
		ft_error(champ);
	while (j)
	{
		champ->exec_size[j--] = (champ->all_weight >> shift) & 255;
		shift += 8;
	}
}

void	ft_translation(t_champ *champ)
{
	int	all_len;
	int	fd;

	ft_magic_header(champ);
	ft_counter_weight(champ);
	ft_cycle(champ);
	ft_exec_to_byte(champ);
	ft_make_exec_size(champ);
	all_len = ft_assembly(champ);
	if (!(fd = open(champ->file_name_cor, O_WRONLY | O_CREAT, 0666)))
		ft_error(champ);
	write(fd, champ->byte_c, all_len);
	ft_printf("Writing output program to %s\n", champ->file_name_cor);
}
