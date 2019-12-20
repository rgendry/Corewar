/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:28:17 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 20:55:58 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_create_name(t_champ *champ)
{
	champ->name->name = ft_memalloc(PROG_NAME_LENGTH);
	if (!(champ->name->name))
		ft_error(champ);
}

int		ft_write_str(t_champ *champ, char *str, int i, int j)
{
	while (str[i] != '\0' && str[i] != '"')
	{
		if (champ->name->cur_len >= PROG_NAME_LENGTH)
			ft_too_long_name(champ);
		champ->name->name[j++] = str[i++];
		champ->name->cur_len++;
	}
	if (str[i] == '"')
	{
		champ->name->f_multi_lines_name = 0;
		ft_check_end(champ, str, i + 1);
	}
	else
	{
		if (champ->name->cur_len > PROG_NAME_LENGTH)
			ft_too_long_name(champ);
	}
	return (i);
}

void	ft_start_check(t_champ *champ, char *str, int i)
{
	while (str[++i])
	{
		if ((str[i] == ' ' || str[i] == '\t') &&
			champ->name->f_multi_lines_name != 1)
			continue;
		if (str[i] == '"' && champ->name->f_multi_lines_name == -1)
		{
			champ->name->f_multi_lines_name = 1;
			i = ft_write_str(champ, str, i + 1, champ->name->cur_len);
			continue;
		}
		else if (str[i] == '"' && champ->name->f_multi_lines_name == 1)
			champ->name->f_multi_lines_name = 0;
		else if (is_comment(str + i))
			break ;
		if ((ft_isascii(str[i]) && champ->name->f_multi_lines_name == 1 &&
			str[i] != '"') || (champ->name->f_multi_lines_name == 0 &&
			str[i] == '\n'))
			continue;
		else
			ft_syntax_error(champ);
	}
}

int		ft_find_start(t_champ *champ, char *str, int i)
{
	int len_cmd;

	len_cmd = ft_strlen(NAME_CMD_STRING);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (ft_strncmp(str + i, NAME_CMD_STRING, len_cmd))
		ft_syntax_error(champ);
	return (i + len_cmd);
}

void	ft_parse_name(t_champ *champ, char *str)
{
	int i;

	i = -1;
	if (!champ->name->name)
		ft_create_name(champ);
	if (ft_strstr(str, NAME_CMD_STRING))
		i = ft_find_start(champ, str, 0);
	if (champ->name->f_multi_lines_name == -1)
		ft_start_check(champ, str, i - 1);
	else
		ft_write_str(champ, str, 0, champ->name->cur_len);
}
