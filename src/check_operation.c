/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/01 18:44:31 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_operation_type(t_champ *champ, char *str, char **token, int label)
{
	if (str && (str[0] == COMMENT_CHAR || str[0] == ALT_COMMENT_CHAR))
		return (2);
	if (is_label(str))
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

char		*spaces(char *str, int i, int j)
{
	char	*new;

	if (!(new = ft_memalloc(ft_strlen(str) * 2)))
		return (NULL);
	while (str[i] != '\0' && str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR)
	{
		if (str[i] == ' ' || str[i] == '\t')
			new[j] = SEPARATOR_CHAR;
		else if (str[i] == DIRECT_CHAR && new[j - 1] != SEPARATOR_CHAR)
		{
			new[j] = SEPARATOR_CHAR;
			i--;
		}
		else
		{
			new[j] = str[i];
			if (new[j] == LABEL_CHAR && new[j - 1] && new[j - 1] != DIRECT_CHAR && new[j - 1] != SEPARATOR_CHAR)
				new[++j] = SEPARATOR_CHAR;
		}
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

t_tokens	*check_operations(t_champ *champ, char *str)
{
	int			type;
	char		*newstr;
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (is_emptystr(str))
		return (NULL);
	newstr = spaces(str, 0, 0);
    new->token = ft_strsplit(newstr, SEPARATOR_CHAR);
	if (!new->token[0])
    {
        ft_strdel(&newstr);
        return (NULL);
    }
	type = check_operation_type(champ, new->token[0], new->token, 0);
	if (type == 1 && new->token[1])
		type = check_operation_type(champ, new->token[1], new->token, 1);
	if (type < 1)
		ft_syntax_error(champ);
	new->next = NULL;
	ft_strdel(&newstr);
	return (new);
}
