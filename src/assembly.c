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

int  ft_assembly(t_champ *champ)
{
    // не добавил длину исполняемого (будет занимать 4 байта) и 4 нулевых после комента
    char *tmp;

    champ->byte_code_all = ft_memjoin(champ->m_header, champ->name->name, 4, 128);
    tmp = champ->byte_code_all;
    champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->four_zero_bytes, 132, 4);
    ft_strdel(&tmp);
    tmp = champ->byte_code_all;
    champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->com->comment, 136, 2048);
    ft_strdel(&tmp);
//    tmp = champ->byte_code_all;
//    champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->four_zero_bytes, 2184, 4);
//    ft_strdel(&tmp);
    tmp =  champ->byte_code_all;
    champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->instr_byte, 2188, champ->instr_byte_len);
    ft_strdel(&tmp);
    return (2184 + champ->instr_byte_len);
}