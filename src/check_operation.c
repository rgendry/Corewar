/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:36:41 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/18 17:23:59 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_operation_type(t_champ *champ, char *str, char **token, int label)
{
	if (ft_strstr(str, "live") || ft_strstr(str, "zjmp")
		|| ft_strstr(str, "fork") || ft_strstr(str, "lfork"))
		return (check_type2(token, label));
	if (ft_strstr(str, "ld") || ft_strstr(str, "lld"))
		return (check_type3(token, label));
	if (ft_strstr(str, "st")) // sti заходит сюда а до своего условия не доходит (можно просто местами поменять)
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
	if (check_label(str))
		return (add_label(&(champ->labels), create_label(str)));
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
			if (new[j] == ':' && new[j - 1] && new[j - 1] != '%')
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

	if (is_emptystr(str))
		return ;
	newstr = spaces(str, 0, 0);
	ft_strdel(&str); // зачем чистить? это же строчка из общего файла,
	// который понадобится дл перевода в байт код
	token = ft_strsplit(newstr, ',');
	type = check_operation_type(champ, token[0], token, 0); // если метка в одной строке "entry:",
//	то она вроде записывается создается список, а здесь возвращается 1 (turtle.s)
	if (type == 1) // поэтому заходит сюда
		type = check_operation_type(champ, token[1], token, 1); // и тут сега
	if (type < 2) // тк c sti заходит в st возвращает 0 и пишет ерор (not tutrle.s)
		ft_error();
}
