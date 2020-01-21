/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:27:13 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 20:57:35 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_end(t_champ *champ, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
			return ;
		else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			ft_error(champ);
		i++;
	}
}

int		ft_write_str_com(t_champ *champ, char *str, int i, int j)
{
	while (str[i] != '\0' && str[i] != '"')
	{
		if (champ->com->cur_len >= COMMENT_LENGTH)
			ft_too_long_com(champ);
		champ->com->comment[j++] = str[i++];
		champ->com->cur_len++;
	}
	if (str[i] == '"')
	{
		champ->com->f_multi_lines_com = 0;
		ft_check_end(champ, str, i + 1);
	}
	else
	{
		if (champ->com->cur_len > COMMENT_LENGTH)
			ft_too_long_com(champ);
	}
	return (i);
}

void	ft_start_check_com(t_champ *champ, char *str, int i)
{
	while (str[++i])
	{
		if ((str[i] == ' ' || str[i] == '\t') &&
			champ->com->f_multi_lines_com != 1)
			continue;
		if (str[i] == '"' && champ->com->f_multi_lines_com == -1)
		{
			champ->com->f_multi_lines_com = 1;
			i = ft_write_str_com(champ, str, i + 1, champ->com->cur_len);
			if (!str[i])
				break ;
			continue;
		}
		else if (str[i] == '"' && champ->com->f_multi_lines_com == 1)
			champ->com->f_multi_lines_com = 0;
		else if (is_comment(str + i))
			break ;
		if ((ft_isascii(str[i]) &&
			champ->com->f_multi_lines_com == 1 && str[i] != '"') ||
			(champ->com->f_multi_lines_com == 0 && str[i] == '\n'))
			continue;
		else
			ft_syntax_error(champ);
	}
}

int		ft_find_start_com(t_champ *champ, char *str, int i)
{
	int len_cmd;

	len_cmd = ft_strlen(COMMENT_CMD_STRING);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (ft_strncmp(str + i, COMMENT_CMD_STRING, len_cmd))
		ft_syntax_error(champ);
	return (i + len_cmd);
}

void	ft_parse_com(t_champ *champ, char *str)
{
	int	i;

	i = -1;
	if (!champ->com->comment)
		ft_create_com(champ);
	if (ft_strstr(str, COMMENT_CMD_STRING))
		i = ft_find_start_com(champ, str, 0);
	if (champ->com->f_multi_lines_com == -1)
		ft_start_check_com(champ, str, i - 1);
	else
		ft_write_str_com(champ, str, 0, champ->com->cur_len);
}
