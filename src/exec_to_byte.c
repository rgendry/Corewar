/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_to_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/29 15:52:22 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_add_arg(t_champ *champ, t_instr *head, char *tmp, int *len)
{
    if (head->arg1)
    {
        tmp = champ->instr_byte;
        champ->instr_byte = ft_memjoin(champ->instr_byte, head->arg1->byte_code, *len, head->arg1->weight);
        *len += head->arg1->weight;
        ft_strdel(&tmp);
    }
    if (head->arg2)
    {
        tmp = champ->instr_byte;
        champ->instr_byte = ft_memjoin(champ->instr_byte, head->arg2->byte_code, *len, head->arg2->weight);
        *len += head->arg2->weight;
        ft_strdel(&tmp);
    }
    if (head->arg3)
    {
        tmp = champ->instr_byte;
        champ->instr_byte = ft_memjoin(champ->instr_byte, head->arg3->byte_code, *len, head->arg3->weight);
        *len += head->arg3->weight;
        ft_strdel(&tmp);
    }
}

void ft_exec_to_byte(t_champ *champ)
{
    t_instr *head;
    char *tmp;
    int len;

    len = 0;
    head = champ->byte_code;
    while (head)
    {
        tmp = champ->instr_byte;
        champ->instr_byte = ft_memjoin(champ->instr_byte, &head->instr, len++, 1);
        ft_strdel(&tmp);
        if (head->type)
        {
            tmp = champ->instr_byte;
            champ->instr_byte = ft_memjoin(champ->instr_byte, &head->type, len++, 1);
            ft_strdel(&tmp);
        }
        ft_add_arg(champ, head, NULL, &len);
        head = head->next;
    }
    champ->instr_byte_len = len;
}
