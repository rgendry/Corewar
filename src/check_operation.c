/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:41 by rgendry           #+#    #+#             */
/*   Updated: 2020/01/18 16:32:08 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_op_type(t_champ *champ, char *str, char **token, int label)
{
	if (str && (str[0] == COMMENT_CHAR || str[0] == ALT_COMMENT_CHAR))
		return (2);
	if (is_label(str))
		return (add_label(&(champ->labels), create_label(champ, str)));
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

char		*spaces(char *str, int i, int j, char *new)
{
	if (!(new = ft_memalloc(ft_strlen(str) * 2)))
		return (NULL);
	while (str[i] != '\0' && str[i] != COMMENT_CHAR &&
		str[i] != ALT_COMMENT_CHAR)
	{
		if (str[i] == ' ' || str[i] == '\t')
			new[j] = SEPARATOR_CHAR;
		else if ((str[i] == DIRECT_CHAR) && new[j - 1] != SEPARATOR_CHAR)
		{
			new[j] = SEPARATOR_CHAR;
			i--;
		}
		else
		{
			new[j] = str[i];
			if (new[j] == LABEL_CHAR && new[j - 1] &&
				new[j - 1] != DIRECT_CHAR && new[j - 1] != SEPARATOR_CHAR)
				new[++j] = SEPARATOR_CHAR;
		}
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

int			check_minus(char **token)
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
		return(1);
	return (0);
}

void		del_label(t_label **labels, char **token)
{
	t_label **head;

	if (!is_label(token[0]))
		return ;
	head = labels;
	while (*head && (*head)->next)
		*head = (*head)->next;
	free (*head);
	*head = NULL;
}

// void		print_labels(t_label *labels)
// {
// 	t_label	*head;

// 	head = labels;
// 	while (head)
// 	{
// 		ft_printf("%s\n", head->name);
// 		head = head->next;
// 	}
// }

char		*added_space(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		if (str[i] == '-' && (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
		{
			newstr[j] = ' ';
			j++;
		}
		newstr[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (newstr);
}

t_tokens	*check_operations(t_champ *champ, char *str)
{
	int			type;
	char		*newstr;
	t_tokens	*new;

	if (is_emptystr(str))
		return (NULL);
	ft_printf("%s\n", str);
	new = malloc(sizeof(t_tokens));
	newstr = spaces(str, 0, 0, NULL);
	new->token = ft_strsplit(newstr, SEPARATOR_CHAR);
	if (!new->token[0])
	{
		ft_strdel(&newstr);
		return (NULL);
	}
	type = check_op_type(champ, new->token[0], new->token, 0);
	if (type == 1 && new->token[1])
		type = check_op_type(champ, new->token[1], new->token, 1);
	if (type < 1)
	{
		if (check_minus(new->token))
		{
			del_label(&(champ->labels), new->token);
			free_arr(&(new->token));
			free(new);
			return (check_operations(champ, added_space(newstr)));
		}
		ft_syntax_error(champ);
	}
	new->next = NULL;
	ft_strdel(&newstr);
	return (new);
}
