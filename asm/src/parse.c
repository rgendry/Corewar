/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:09 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 20:39:27 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_file_name(t_champ *champ, char *name)
{
	int		len;
	char	*tmp;

	len = ft_strlen(name);
	if (name[len - 1] != 's' || name[len - 2] != '.')
		ft_usage();
	champ->file_name_cor = ft_strndup(name, len - 1);
	tmp = champ->file_name_cor;
	champ->file_name_cor = ft_strjoin(champ->file_name_cor, "cor");
	ft_strdel(&tmp);
}

void	add_token(t_tokens **head, t_tokens *new)
{
	t_tokens	*next;

	if (!new)
		return ;
	next = *head;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = new;
	}
	else
		*head = new;
}

void	ft_delnl(char *str)
{
	int	len;

	len = ft_strlen(str);
	str[len - 1] = '\0';
}

void	ft_check_str(t_champ *champ, char *str)
{
	if (is_comment(str) || is_emptystr(str))
		return ;
	else if (ft_strstr(str, NAME_CMD_STRING) ||
		champ->name->f_multi_lines_name == 1)
		ft_parse_name(champ, str);
	else if (ft_strstr(str, COMMENT_CMD_STRING) ||
		champ->com->f_multi_lines_com == 1)
		ft_parse_com(champ, str);
	else if (*str == '\n')
		return ;
	else if (champ->name->name && champ->com->comment)
	{
		ft_delnl(str);
		add_token(&champ->string, check_operations(champ, str));
	}
	else
		ft_errors(champ);
}

void	ft_parse(t_champ *champ, int end)
{
	char	*start;
	char	*tmp;

	start = champ->file_str;
	while (*start != '\0')
	{
		champ->num_lines_file++;
		end = ft_numln(start);
		tmp = ft_strndup(start, end);
		start += end;
		ft_check_str(champ, tmp);
		ft_strdel(&tmp);
	}
	if (!champ->string)
		ft_error(champ);
	ft_strdel(&champ->file_str);
	ft_errors(champ);
}
