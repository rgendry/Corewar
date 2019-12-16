/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/15 18:07:29 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_usage()
{
    ft_printf("Enter only one name of a champion *.s\n");
    exit (1);
}

void ft_too_long_name(t_champ *champ)
{
    ft_printf("Champion name too long (Max length %d)\n", 128);
    ft_clear_everything(champ);
    exit (EXIT_FAILURE);
}

void ft_too_long_com(t_champ *champ)
{
    ft_printf("Champion comment too long (Max length %d)\n", COMMENT_LENGTH);
    ft_clear_everything(champ);
    exit (EXIT_FAILURE);
}

void ft_syntax_error(t_champ *champ)
{
    ft_printf("Syntax error at line number %d\n", champ->num_lines_file);
    ft_clear_everything(champ);
    exit (EXIT_FAILURE);
}

void ft_error(t_champ *champ)
{
    ft_printf("Error\n");
    ft_clear_everything(champ);
    exit (EXIT_FAILURE);
}

void ft_errors(t_champ *champ)
{
    if (champ->name->name == NULL)
    {
        printf("In the champion file with the extension .s missing name of champion\n");
        ft_clear_everything(champ);
        exit (EXIT_FAILURE);
    }
    if (champ->com->comment == NULL)
    {
        printf("In the champion file with the extension .s missing comment of champion\n");
        ft_clear_everything(champ);
        exit (EXIT_FAILURE);
    }
    if (champ->name->f_multi_lines_name == 1 || champ->com->f_multi_lines_com == 1)
    {
        printf("In the champion file with the extension .s missing closing quote\n");
        ft_clear_everything(champ);
        exit (EXIT_FAILURE);
    }
}
