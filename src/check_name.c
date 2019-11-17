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

void ft_parse_name(t_champ *champ, char *str, int i)
{
    int decl_name_len;

    decl_name_len = ft_strlen(NAME_CMD_STRING);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (ft_strncmp(NAME_CMD_STRING, str + i, decl_name_len))
        ft_syntax_error(champ);
    i += decl_name_len;
    ft_printf("%d\n", i);
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
