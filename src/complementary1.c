/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:19 by ubartemi          #+#    #+#             */
/*   Updated: 2020/01/19 16:43:36 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_check_cmd_string(t_champ *champ, char *str, int i, char cmd)
{
	int len_decl_name;

	len_decl_name = ft_strlen(cmd == 'n' ? NAME_CMD_STRING :
			COMMENT_CMD_STRING);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (ft_strncmp(cmd == 'n' ? NAME_CMD_STRING : COMMENT_CMD_STRING,
				str + i, len_decl_name))
		ft_syntax_error(champ);
	i += len_decl_name;
	return (i - 1);
}

int		is_emptystr(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
			break ;
		if (str[i] == ' ' || str[i] == '\t')
			continue;
		return (0);
	}
	return (1);
}

void	ft_initialization(t_champ *champ)
{
	if (!(champ->com = malloc(sizeof(t_com))) ||
			!(champ->name = malloc(sizeof(t_name))))
		ft_error(champ);
	if (!(champ->four_zero_bytes = ft_memalloc(4)))
		ft_error(champ);
	champ->com->comment = NULL;
	champ->name->name = NULL;
	champ->byte_code = NULL;
	champ->labels = NULL;
	champ->file_str = NULL;
	champ->string = NULL;
	champ->exec_size = NULL;
	champ->instr_byte = NULL;
	champ->instr_byte = NULL;
	champ->len_file = 0;
	champ->num_lines_file = 0;
	champ->com->f_multi_lines_com = -1;
	champ->name->f_multi_lines_name = -1;
	champ->name->cur_len = 0;
	champ->com->cur_len = 0;
	champ->all_weight = 0;
	champ->instr_byte_len = 0;
}

int		is_comment(char *str)
{
	if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int		check_minus(char **token)
{
	char	*error;

	if (is_label(token[0]))
		error = token[1];
	else
		error = token[0];
	while (*error >= 'a' && *error <= 'z')
		error++;
	if (*error == '-')
		error++;
	else
		return (0);
	while (*error >= '0' && *error <= '9')
		error++;
	if (*error == '\0')
		return (1);
	return (0);
}
