/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/17 18:57:32 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_operation_type(char *str, char **token, int label)
{
	if (ft_strstr(str, "live") || ft_strstr(str, "zjmp")
		|| ft_strstr(str, "fork") || ft_strstr(str, "lfork"))
		return (check_type2(token, label));
	if (ft_strstr(str, "ld") || ft_strstr(str, "lld"))
		return (check_type3(token, label));
	if (ft_strstr(str, "st"))
		return (check_type4(token, label));
	if (ft_strstr(str, "add") || ft_strstr(str, "sub"))
		return (check_type5(token, label));
	if (ft_strstr(str, "and") || ft_strstr(str, "or")
		|| ft_strstr(str, "xor"))
		return (check_type6(token, label));
	if (ft_strstr(str, "ldi") || ft_strstr(str, "lldi"))
		return (check_type7(token, label));
	if (ft_strstr(str, "sti"))
		return (check_type8(token, label));
	if (ft_strstr(str, "aff"))
		return (check_type9(token, label));
	if (ft_strchr(str, ':'))
		return (1);
	return (0);
}

char	*spaces(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) * 2))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			new[j] = ',';
		else if ((str[i] == '%' || str[i] == ':') && new[j - 1] != ',')
		{
			new[j] = ',';
			i--;
		}
		else
			new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

void	check_opertaions(char *str)
{
	int		type;
	char	*newstr;
	char	**token;

	if (is_emptystr(str))
		return ;
	newstr = spaces(str);
	ft_strdel(&str);
	token = ft_strsplit(newstr, ',');
	type = check_operation_type(token[0], token, 0);
	if (type == 1)
		type = check_operation_type(token[1], token, 1);
	if (type < 2)
		ft_error();
}
