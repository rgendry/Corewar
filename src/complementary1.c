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
        ft_printf("%s\n", matrix[i]);
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
    if (!(champ->com = malloc(sizeof(t_com))) || !(champ->name = malloc(sizeof(t_name))))
        ft_error();
    if (!(champ->four_zero_bytes = ft_memalloc(4)))
        ft_error();
    champ->com->comment = NULL;
    champ->name->name = NULL;
    champ->byte_code = NULL;
    champ->labels = NULL;
    champ->file = NULL;
    champ->string = NULL;
    champ->len_file = 0;
    champ->num_lines_file = 0;
    champ->com->f_multi_lines_com = -1;
    champ->name->f_multi_lines_name = -1;
    champ->name->len_name = 0;
    champ->start_instr = 0;
    champ->all_weight = 0;

}

int is_comment(char *str)
{
    if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
        return (1);
    return (0);
}

