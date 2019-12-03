/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/01 19:16:21 by rgendry          ###   ########.fr       */
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
        weight++;
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

// void    print_labels(t_champ *champ)
// {
//     t_label *head;

//     head = champ->labels;
//     while (head)
//     {
//         ft_printf("%s ", head->name);
//         ft_printf("%d\n", head->place);
//         head = head->next;
//     }
// }

void ft_make_exec_size(t_champ *champ)
{
/*    int j;
    int i;

    i = 3;
    j = (champ->all_weight / 255) + 1;
    if (!(champ->exec_size = ft_memalloc(4)))
        ft_error();
    while (j)
    {
        champ->exec_size[i--] = champ->all_weight % 255;
        champ->all_weight /= 255;
        j--;
    }*/
    int shift;
    int j;

    shift = 0;
    j = 3;
    if (!(champ->exec_size = ft_memalloc(4)))
        ft_error();
    while (j)
    {
        champ->exec_size[j--] = (champ->all_weight >> shift) & 255;
        shift += 8;
    }
}

void ft_translation(t_champ *champ)
{
    int all_len;
    int fd;

    ft_magic_header(champ);
    ft_counter_weight(champ);
    ft_cycle(champ);
    ft_exec_to_byte(champ); // тут будем записывать в отдельную строку (чтобы 2,5к байт каждый раз не переписывать)
    ft_make_exec_size(champ);
    all_len = ft_assembly(champ); //а уже тут будет сборка всех частей в общую строку байт кода

     if (!(fd = open(champ->file_name_cor, O_WRONLY | O_CREAT, 0666)))
        ft_error();
    //write(fd, champ->instr_byte, champ->instr_byte_len);
    write(fd, champ->byte_code_all, all_len);
    ft_printf("successfully created\n");
}
