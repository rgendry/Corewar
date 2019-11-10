/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:37:35 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 14:37:37 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_write_name(t_champ *champ, char *str, int i)
{
    char *tmp;

    if (champ->name->f_multi_lines_name == -1)
        ft_syntax_error(champ);
    while (str[i] && str[i] != '"')
        i++;
    if (ft_strstr(str, NAME_CMD_STRING))
    {
        tmp = ft_strndup(str + i + 1, champ->name->len_name);
        if (champ->name->f_multi_lines_name == 1)
            champ->name->name = ft_strjoin(tmp, "\n");
        else
            champ->name->name = ft_strdup(tmp);
        ft_strdel(&tmp);
    }
    else
    {
        tmp = ft_strndup(str + i + 1, champ->name->len_name);
        champ->name->name = ft_strjoin(tmp, str + i + 1);
        ft_strdel(&tmp);
    }
}

void ft_flag_zero(t_champ *champ, char *str, int i)
{
    while (str[++i])
    {
        if ((str[i] == ' ' || str[i] == '\t') && champ->name->f_multi_lines_name != 1)
            continue;
        if ((ft_isalpha(str[i]) || str[i] == ' ' || str[i] == '\t')
        && champ->name->f_multi_lines_name == 1)
        {
            champ->name->len_name++;
            continue;
        }
        if (str[i] == '"' && champ->name->f_multi_lines_name == -1)
            champ->name->f_multi_lines_name = 1;
        else if (str[i] == '"' && champ->name->f_multi_lines_name == 1)
            champ->name->f_multi_lines_name = 0;
        else
            ft_syntax_error(champ);
    }
    ft_write_name(champ, str, 0);
}

void ft_flag_one(t_champ *champ, char *str, int i, char *name)
{
    char *tmp;
    char *tmp1;

    while (str[i] && str[i] != '"')
        i++;
    if (str[i] && str[i] == '"')
    {
        name = ft_strndup(str, i);
        tmp = champ->name->name;
        champ->name->name = ft_strjoin(champ->name->name, name);
        ft_strdel(&name);
        ft_strdel(&tmp);
        champ->name->f_multi_lines_name = 0;
    }
    else
    {
        tmp1 = champ->name->name;
        tmp = ft_strjoin(str, "\n");
        champ->name->name = ft_strjoin(champ->name->name, tmp);
        ft_strdel(&tmp1);
        ft_strdel(&tmp);
    }
}

void ft_parse_name(t_champ *champ, char *str)
{
    if (champ->name->f_multi_lines_name == -1)
        ft_flag_zero(champ, str, ft_check_cmd_string(champ, str, 0, 'n'));
    else
        ft_flag_one(champ, str, 0, NULL);
    if (ft_strlen(champ->name->name) >= PROG_NAME_LENGTH)
        ft_syntax_error(champ);
}
