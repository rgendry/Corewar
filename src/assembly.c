/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:52:39 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/15 14:52:41 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_assembly(t_champ *champ)
{
    char *tmp;

    champ->byte_code = ft_strjoin((char*)champ->m_header, champ->name->name);
    tmp = champ->byte_code;
    champ->byte_code = ft_strjoin(champ->byte_code, champ->com->comment);
    ft_strdel(&tmp);
    printf("%s\n", champ->byte_code);
}