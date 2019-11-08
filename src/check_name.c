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

void ft_flag_zero(t_champ *champ, int len_decl_name, char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (ft_strncmp(NAME_CMD_STRING, str + i, len_decl_name))
        ft_syntax_error(champ);
    i += len_decl_name;
    while (str[++i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            continue;
        if (ft_isalpha(str[i]) && champ->name->f_multi_lines_name == 1)
            continue;
        if (str[i] == '\"' && champ->name->f_multi_lines_name == 0)
            champ->name->f_multi_lines_name = 1;
        else if (str[i] == '\"' && champ->name->f_multi_lines_name == 1)
            champ->name->f_multi_lines_name = 0;
        else
            ft_syntax_error(champ);
    }
}

void ft_parse_name(t_champ *champ, char *str, int i)
{
    int len_decl_name;

    len_decl_name = ft_strlen(NAME_CMD_STRING);
    if (champ->name->f_multi_lines_name == 0)
        ft_flag_zero(champ, len_decl_name, str, -1);
//    else
//        ft_flag_one();

}
