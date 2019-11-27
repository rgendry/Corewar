/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/25 16:17:26 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_add_arg(t_champ *champ, t_instr *head, char *tmp)
{
    if (head->arg1)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_strjoin(champ->exec_byte, head->arg1);
        ft_strdel(&tmp);
    }
    if (head->arg2)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_strjoin(champ->exec_byte, head->arg2);
        ft_strdel(&tmp);
    }
    if (head->arg3)
    {
        tmp = champ->exec_byte;
        champ->exec_byte = ft_strjoin(champ->exec_byte, head->arg3);
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
        champ->exec_byte = ft_strjoin(champ->exec_byte, &head->instr);
        ft_strdel(&tmp);
        if (head->type)
        {
            tmp = champ->exec_byte;
            champ->exec_byte = ft_strjoin(champ->exec_byte, &head->type);
            ft_strdel(&tmp);
        }
        ft_add_arg(champ, head, NULL);
        head = head->next;
    }
}