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

void ft_add_arg(t_champ *champ, t_instr *head, char *tmp)
{
    if (head->arg1)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_memjoin(champ->exec_byte, head->arg1->byte_code, 2186, head->arg1->weight);
        ft_strdel(&tmp);
    }
    if (head->arg2)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_memjoin(champ->exec_byte, head->arg2->byte_code, 2186 + head->arg1->weight, head->arg2->weight);
        ft_strdel(&tmp);
    }
    if (head->arg3)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_memjoin(champ->exec_byte, head->arg3->byte_code, 2186 + head->arg1->weight + head->arg2->weight, head->arg3->weight);
        ft_strdel(&tmp);
    }
}

void ft_exec_to_byte(t_champ *champ)
{
    t_instr *head;
    char *tmp;

    head = champ->byte_code;
    while (head)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_memjoin(champ->exec_byte, &head->instr, 2184, 1);
        ft_strdel(&tmp);
        if (head->type)
        {
            tmp = champ->exec_byte;
            champ->exec_byte = ft_memjoin(champ->exec_byte, &head->type, 2185, 1);
            ft_strdel(&tmp);
        }
        ft_add_arg(champ, head, NULL);
        head = head->next;
    }
}
