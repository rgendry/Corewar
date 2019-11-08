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

void ft_print_matrix(char **matrix)
{
    int i;

    i = -1;
    while (matrix[++i])
    {
        ft_printf("%s\n", matrix[i]);
    }
}

void ft_usage()
{
    printf("Enter only one name of a champion *.s\n");
    exit (1);
}

void ft_syntax_error(t_champ *champ)
{
    printf("Syntax error at line number %d\n", champ->num_lines_file);
    exit (1);
}

void ft_error()
{
    printf("Error\n");
    exit (1);
}

void    ft_initialization(t_champ *champ)
{
    champ->len_file = 0;
    champ->num_lines_file = 0;
    champ->file = NULL;
    champ->name = NULL;
    if (!(champ->com = malloc(sizeof(t_com))) || !(champ->name = malloc(sizeof(t_name))))
        ft_error();
    champ->com->f_multi_lines_com = 0;
    champ->com->comment = NULL;
    champ->name->f_multi_lines_name = 0;
    champ->name->name = NULL;

}
