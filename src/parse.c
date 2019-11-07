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

void ft_check_name(char *name)
{
    int len;

    len = ft_strlen(name);
    if (name[len - 1] != 's' || name[len - 2] != '.')
        ft_usage();
}

void ft_parse_com(char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\n')
    {
        write(1, &str[i], 1);
    }
}


void ft_check_str(t_champ *champ, char *str)
{
//    if (ft_strstr(NAME_CMD_STRING, str))
//        ft_parse_name(str);
     if (ft_strstr(COMMENT_CMD_STRING, str))
        ft_parse_com(str);
}

void ft_parse(t_champ *champ, int i)
{
    int start;

    start = 0;
    while (champ->file[++i])
    {
        ft_check_str(champ, champ->file[i]);
    }
}
