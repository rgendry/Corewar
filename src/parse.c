/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:09 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/18 17:12:03 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_check_file_name(t_champ *champ, char *name)
{
    int len;
    char *tmp;

    len = ft_strlen(name);
    if (name[len - 1] != 's' || name[len - 2] != '.')
        ft_usage();
    champ->file_name_cor = ft_strndup(name, len - 1);
    tmp = champ->file_name_cor;
    champ->file_name_cor = ft_strjoin(champ->file_name_cor, "cor");
    ft_strdel(&tmp);
}

void ft_check_str(t_champ *champ, char *str)
{
    if (is_comment(str))
        return;
    else if (ft_strstr(str, NAME_CMD_STRING) || champ->name->f_multi_lines_name == 1)
        ft_parse_name(champ, str);
    else if (ft_strstr(str, COMMENT_CMD_STRING) || champ->com->f_multi_lines_com == 1)
        ft_parse_com(champ,str);
    else if (champ->name->name && champ->com->comment)
        check_opertaions(champ, str);
    else
        ft_errors(champ);
}

void ft_parse(t_champ *champ, int i)
{
    while (champ->file[++i])
    {
        champ->num_lines_file++;
        ft_check_str(champ, champ->file[i]);
    }
    ft_errors(champ);
}
