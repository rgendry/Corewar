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
    ft_printf("Enter only one name of a champion *.s\n");
    exit (1);
}

void ft_syntax_error(t_champ *champ)
{
    ft_printf("Syntax error at line number %d\n", champ->num_lines_file);
    exit (EXIT_FAILURE);
}

void ft_error()
{
    ft_printf("Error\n");
    exit (EXIT_FAILURE);
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
}

int ft_check_cmd_string(t_champ *champ, char *str,int i, char CMD)
{
    int len_decl_name;

    len_decl_name = ft_strlen(CMD == 'n' ? NAME_CMD_STRING : COMMENT_CMD_STRING);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (ft_strncmp(CMD == 'n' ? NAME_CMD_STRING : COMMENT_CMD_STRING, str + i, len_decl_name))
        ft_syntax_error(champ);
    i += len_decl_name;
    return (i - 1);
}

int is_emptystr(char *str)
{
    int i;

    i = -1;
    if (!str)
        return (1);
    while (str[++i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            continue;
        return (0);
    }
    return (1);
}

void    ft_initialization(t_champ *champ)
{
    champ->len_file = 0;
    champ->num_lines_file = 0;
    champ->file = NULL;
    champ->name = NULL;
    if (!(champ->com = malloc(sizeof(t_com))) || !(champ->name = malloc(sizeof(t_name))))
        ft_error();
    champ->com->f_multi_lines_com = -1;
    champ->com->comment = NULL;
    champ->name->f_multi_lines_name = -1;
    champ->name->name = NULL;
    champ->name->len_name = 0;
}

int is_comment(char *str)
{
    if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
        return (1);
    return (0);
}

void ft_errors(t_champ *champ)
{
    if (champ->name->name == NULL)
    {
        printf("In the champion file with the extension .s missing name of champion\n");
        exit (EXIT_FAILURE);
    }
    if (champ->com->comment == NULL)
    {
        printf("In the champion file with the extension .s missing comment of champion\n");
        exit (EXIT_FAILURE);
    }
    if (champ->name->f_multi_lines_name == 1 || champ->com->f_multi_lines_com == 1)
    {
        printf("In the champion file with the extension .s missing closing quote\n");
        exit (EXIT_FAILURE);
    }
}
