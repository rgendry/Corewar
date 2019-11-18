/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:37:25 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 14:37:27 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_write_comment(t_champ *champ, char *str, int i)
{
    char *tmp;

    if (champ->com->f_multi_lines_com == -1)
        ft_syntax_error(champ);
    while (str[i] && str[i] != '"')
        i++;
    if (ft_strstr(str, COMMENT_CMD_STRING))
    {
        tmp = ft_strndup(str + i + 1, champ->com->len_com);
        if (champ->com->f_multi_lines_com == 1)
            champ->com->comment = ft_strjoin(tmp, "\n");
        else
            champ->com->comment = ft_strdup(tmp);
        ft_strdel(&tmp);
    }
    else
    {
        tmp = ft_strndup(str + i + 1, champ->com->len_com);
        champ->com->comment = ft_strjoin(tmp, str + i + 1);
        ft_strdel(&tmp);
    }
}

void ft_flag_minus(t_champ *champ, char *str, int i)
{
    while (str[++i])
    {
        if ((str[i] == ' ' || str[i] == '\t') && champ->com->f_multi_lines_com != 1)
            continue;
        if (ft_isascii(str[i]) && champ->com->f_multi_lines_com == 1 && str[i] != '"')
        {
            champ->com->len_com++;
            continue;
        }
        if (str[i] == '"' && champ->com->f_multi_lines_com == -1)
            champ->com->f_multi_lines_com = 1;
        else if (str[i] == '"' && champ->com->f_multi_lines_com == 1)
            champ->com->f_multi_lines_com = 0;
        else
            ft_syntax_error(champ);
    }
    ft_write_comment(champ, str, 0);
}

void ft_flag_plus(t_champ *champ, char *str, int i, char *name)
{
    char *tmp;
    char *tmp1;

    while (str[i] && str[i] != '"')
        i++;
    if (str[i] && str[i] == '"')
    {
        name = ft_strndup(str, i);
        tmp = champ->com->comment;
        champ->com->comment = ft_strjoin(champ->com->comment, name);
        ft_strdel(&name);
        ft_strdel(&tmp);
        champ->com->f_multi_lines_com = 0;
    }
    else
    {
        tmp1 = champ->com->comment;
        tmp = ft_strjoin(str, "\n");
        champ->com->comment = ft_strjoin(champ->com->comment, tmp);
        ft_strdel(&tmp1);
        ft_strdel(&tmp);
    }
}

void ft_parse_com(t_champ *champ, char *str)
{
    if (champ->com->f_multi_lines_com == -1)
        ft_flag_minus(champ, str, ft_check_cmd_string(champ, str, 0, 'c'));
    else
        ft_flag_plus(champ, str, 0, NULL);
    if (ft_strlen(champ->com->comment) >= COMMENT_LENGTH)
        ft_syntax_error(champ);
}