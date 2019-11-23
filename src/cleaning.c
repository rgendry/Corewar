/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 13:41:22 by ubartemi         ###   ########.fr       */
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

void ft_clear_everything(t_champ *champ, int i)
{
    while (champ->file[++i])
        free(champ->file[i]);
    free(champ->file);
    ft_strdel(&champ->name->name);
    ft_strdel(&champ->com->comment);
    free(champ->name);
    free(champ->com);
    free_nodes(&(champ->labels));
    ft_strdel(&champ->file_name_cor);
    ft_strdel(&champ->byte_code);
    ft_strdel(&champ->m_header);
    ft_strdel(&champ->four_zero_bytes);

}