/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/04 17:27:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void free_nodes(t_label **nodes)
{
    t_label *node;
    t_label *next;

    node = *nodes;
    while (node)
    {
        next = node->next;
        ft_strdel(&(node->name));
        node->next = NULL;
        free(node);
        node = next;
    }
    *nodes = NULL;
}

void free_instr(t_instr **intr)
{
    t_instr *node;
    t_instr *next;

    node = *intr;
    while (node)
    {
        next = node->next;
        // ft_strdel(&((char *)node->arg1->byte_code));
        free(node->arg1->byte_code);
        free(node->arg1);
        // ft_strdel((char *)&(node->arg2->byte_code));
        free(node->arg2->byte_code);
        free(node->arg2);
        // ft_strdel((char *)&(node->arg3->byte_code));
        free(node->arg3->byte_code);
        free(node->arg3);
        node->next = NULL;
        free(node);
        node = next;
    }
    *intr = NULL;
}

void free_arr(char ***arr)
{
    int i;

    i = 0;
    while ((*arr)[i])
    {
        free((*arr)[i]);
        (*arr)[i] = NULL;
        i++;
    }
    free(*arr);
    *arr = NULL;
}

void ft_free_tokens(t_champ *champ)
{
    t_tokens *head;
    t_tokens *next;

    head = champ->string;
    while (head)
    {
        next = head->next;
        free_arr(&head->token);
        head->next = NULL;
        free(head);
        head = next;
    }
}

void ft_clear_everything(t_champ *champ)
{
    ft_free_tokens(champ);
    free(champ->name->name);
    free(champ->com->comment);
    free(champ->name);
    free(champ->com);
    free_nodes(&(champ->labels));
    ft_strdel(&champ->file_name_cor);
    free(champ->byte_code_all);
    free(champ->m_header);
    free(champ->four_zero_bytes);
    free(champ->instr_byte);
    free(champ->byte_code);
}
