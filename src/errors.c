/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 20:43:28 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_usage(void)
{
	ft_printf("Enter only one name of a champion *.s\n");
	exit(EXIT_FAILURE);
}

void	ft_lex_error(t_champ *champ)
{
	ft_printf("Lexical error at line number %d\n", champ->num_lines_file);
	ft_clear_everything(champ);
	exit(EXIT_FAILURE);
}

void	ft_syntax_error(t_champ *champ)
{
	ft_printf("Syntax error at line number %d\n", champ->num_lines_file);
	ft_clear_everything(champ);
	exit(EXIT_FAILURE);
}

void	ft_error(t_champ *champ)
{
	ft_printf("Error\n");
	ft_clear_everything(champ);
	exit(EXIT_FAILURE);
}

void	ft_errors(t_champ *champ)
{
	if (champ->name->name == NULL)
	{
		ft_printf("In the champion file with the extension ");
		ft_printf(".s missing name of champion\n");
		ft_clear_everything(champ);
		exit(EXIT_FAILURE);
	}
	if (champ->com->comment == NULL)
	{
		ft_printf("In the champion file with the extension ");
		ft_printf(".s missing comment of champion\n");
		ft_clear_everything(champ);
		exit(EXIT_FAILURE);
	}
	if (champ->name->f_multi_lines_name == 1 ||
		champ->com->f_multi_lines_com == 1)
	{
		ft_printf("In the champion file with the extension ");
		ft_printf(".s missing closing quote\n");
		ft_clear_everything(champ);
		exit(EXIT_FAILURE);
	}
}
