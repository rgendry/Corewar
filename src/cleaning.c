/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/15 18:41:54 by rgendry          ###   ########.fr       */
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
        if (node->arg1 && node->arg1->byte_code)
        {
            free(node->arg1->byte_code);
            free(node->arg1);
        }
        if (node->arg2 && node->arg2->byte_code)
        {
            free(node->arg2->byte_code);
            free(node->arg2);
        }
        if (node->arg3 && node->arg3->byte_code)
        {
            free(node->arg3->byte_code);
            free(node->arg3);
        }
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

// void    ft_free_byte(t_champ *champ)
// {
//     t_instr *head;
//     t_instr *next;

//     head = champ->byte_code;
//     while (head)
//     {
//         next = head->next;
//         free(head->arg1);
//         free(head->arg2);
//         free(head->arg3);
//         head->next = NULL;
//         free(head);
//         head = next;
//     }
// }

void ft_clear_everything(t_champ *champ)
{
    if (champ->string)
        ft_free_tokens(champ); // look up
    if (champ->byte_code)
        free_instr(&(champ->byte_code));
    if (champ->name && champ->name->name)
    {
        free(champ->name->name);
        free(champ->name);
    }
    if (champ->com && champ->com->comment)
    {
        free(champ->com->comment);
        free(champ->com);
    }
    if (champ->labels)
        free_nodes(&(champ->labels));
    if (champ->file_name_cor)
        ft_strdel(&champ->file_name_cor);
    if (champ->byte_code_all)
        free(champ->byte_code_all);
    if (champ->m_header)
        free(champ->m_header);
    if (champ->four_zero_bytes)
        free(champ->four_zero_bytes);
    if (champ->instr_byte)
        free(champ->instr_byte);
    if (champ->byte_code)
        free(champ->byte_code);
}
