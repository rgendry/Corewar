/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:09 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 19:45:10 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_check_file_name(char *name)
{
    int len;

    len = ft_strlen(name);
    if (name[len - 1] != 's' || name[len - 2] != '.')
        ft_usage();
}

void ft_check_str(t_champ *champ, char *str)
{
    if (ft_strstr(str, NAME_CMD_STRING) || champ->name->f_multi_lines_name)
        ft_parse_name(champ, str, 0);
    else if (ft_strstr(str, COMMENT_CMD_STRING) || champ->com->f_multi_lines_com)
        ft_parse_com(champ, str);
    else
        check_opertaions(str);
}

void ft_parse(t_champ *champ, int i)
{
    int start;

    start = 0;
    while (champ->file[++i])
    {
        ft_check_str(champ, champ->file[i]);
        champ->num_lines_file++;
    }
}
