/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_se.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/18 16:02:01 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	*ft_memjoin(unsigned char *s1, unsigned char *s2,
		int len1, int len2)
{
	int				len;
	unsigned char	*newstr;
	unsigned char	*begin;

	len = len1 + len2;
	newstr = ft_memalloc(len);
	begin = newstr;
	if (s1 == NULL && s2 == NULL)
		return ((unsigned char *)ft_strnew(0));
	else if (s1 == NULL)
		ft_memcpy(newstr, s2, len2);
	else if (s2 == NULL)
		ft_memcpy(newstr, s1, len1);
	while (len1--)
		*newstr++ = *s1++;
	while (len2--)
		*newstr++ = *s2++;
	return (begin);
}
