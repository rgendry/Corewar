/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/22 14:26:01 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_operation_type(t_champ *champ, char *str, char **token, int label)
{
	if (str[0] == COMMENT_CHAR || str[0] == ALT_COMMENT_CHAR)
		return (2);
	if (check_label(str))
		return (add_label(&(champ->labels), create_label(str)));
	if (!ft_strcmp(str, "live") || !ft_strcmp(str, "zjmp")
		|| !ft_strcmp(str, "fork") || !ft_strcmp(str, "lfork"))
		return (check_type2(token, label));
	if (!ft_strcmp(str, "ldi") || !ft_strcmp(str, "lldi"))
		return (check_type7(token, label));
	if (!ft_strcmp(str, "ld") || !ft_strcmp(str, "lld"))
		return (check_type3(token, label));
	if (!ft_strcmp(str, "sti"))
		return (check_type8(token, label));
	if (!ft_strcmp(str, "st"))
		return (check_type4(token, label));
	if (!ft_strcmp(str, "add") || !ft_strcmp(str, "sub"))
		return (check_type5(token, label));
	if (!ft_strcmp(str, "and") || !ft_strcmp(str, "or")
		|| !ft_strcmp(str, "xor"))
		return (check_type6(token, label));
	if (!ft_strcmp(str, "aff"))
		return (check_type9(token, label));
	return (0);
}

char	*spaces(char *str, int i, int j)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) * 2))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			new[j] = ',';
		else if (str[i] == '%' && new[j - 1] != ',')
		{
			new[j] = ',';
			i--;
		}
		else
		{
			new[j] = str[i];
			if (new[j] == ':' && new[j - 1] && new[j - 1] != '%' && new[j - 1] != ',')
				new[++j] = ',';
		}
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

void	check_opertaions(t_champ *champ, char *str)
{
	int		type;
	char	*newstr;
	char	**token;

	if (champ->start_instr == 0)
	    champ->start_instr = champ->num_lines_file;
	if (is_emptystr(str))
		return ;
	newstr = spaces(str, 0, 0);
	token = ft_strsplit(newstr, ',');
	type = check_operation_type(champ, token[0], token, 0);
	if (type == 1 && token[1])
		type = check_operation_type(champ, token[1], token, 1);
	if (type < 1)
		ft_syntax_error(champ);
    free_arr(&token);
    ft_strdel(&newstr);
}
