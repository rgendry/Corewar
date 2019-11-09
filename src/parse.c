/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:09 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 13:41:13 by ubartemi         ###   ########.fr       */
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
        ft_parse_name(champ, str);
    else if (ft_strstr(str, COMMENT_CMD_STRING) || champ->com->f_multi_lines_com)
        ft_parse_com(champ,str);
    // else инструкции
}

void ft_parse(t_champ *champ, int i)
{
    int start;

    start = 0;
    while (champ->file[++i])
    {
        champ->num_lines_file++;
        ft_check_str(champ, champ->file[i]);
    }
}
