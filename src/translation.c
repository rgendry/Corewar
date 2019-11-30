/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/27 17:18:59 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_arg_weight(char *str, int type)
{
    if (is_comment(str))
        return (0);
    if (check_arg_type(str) == 1)
        return (1);
    if (check_arg_type(str) == 2)
    {
        if ((type >= 1 && type <= 8) || type == 13 || type == 16)
            return (4);
        if ((type >= 9 && type <= 12) || type == 14 || type == 15)
            return (2);
    }
    if (check_arg_type(str) == 3)
        return (2);
    return (0);
}

int ft_count_weight(char **token, int label)
{
    int i;
    int type;
    int weight;

    i = 1;
    weight = 1;
    type = operation_type(token[0 + label]);
    if (type != 1 && type != 9 && type != 12 && type != 15)
        weight += 2;
    while (token[i + label])
    {
        weight += ft_arg_weight(token[i + label], type);
        i++;
    }
    return (weight);
}

void	set_label(t_champ *champ, char *str, int place)
{
    t_label *head;

    head = champ->labels;
    while (head)
    {
        if (!(ft_strcmp(str, head->name)))
        {
            head->place = place;
            return ;
        }
        head = head->next;
    }
    ft_error();
}


void ft_counter_weight(t_champ *champ)
{
    int label;
    t_tokens *head;

    label = 0;
    head = champ->string;
    while (head)
    {
        label = 0;
        if (is_label(head->token[0]))
        {
            set_label(champ, head->token[0], champ->all_weight);
            label = 1;
        }
        if (head->token[0 + label] && !is_comment(head->token[0 + label]))
            champ->all_weight += ft_count_weight(head->token, label);
        head = head->next;
    }
}

//void    print_labels(t_champ *champ)
//{
//    while (champ->labels)
//    {
//        ft_printf("%s ", champ->labels->name);
//        ft_printf("%d\n", champ->labels->place);
//        champ->labels = champ->labels->next;
//    }
//}

void ft_translation(t_champ *champ)
{
    int all_len;

    ft_magic_header(champ);
    ft_counter_weight(champ);
    ft_cycle(champ);
    ft_exec_to_byte(champ); // тут будем записывать в отдельную строку (чтобы 2,5к байт каждый раз не переписывать)
    all_len = ft_assembly(champ); //а уже тут будет сборка всех частей в общую строку байт кода

     if ((champ->fd_byte = open("byte_code", O_RDWR | O_TRUNC | O_CREAT | S_IWRITE | S_IREAD)) == -1)
        ft_error();
     write(champ->fd_byte, champ->byte_code_all, all_len);

}
