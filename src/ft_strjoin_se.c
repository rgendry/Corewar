/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_se.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:36 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/27 17:17:46 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"


char	*ft_memjoin(char *s1, char *s2, int len1, int len2)
{
    int len;
    char *newstr;
    char *begin;

    len = len1 + len2;
    newstr = (char*)malloc(sizeof(char) * len);
    begin = newstr;
    if (s1 == NULL && s2 == NULL)
        return (ft_strnew(0));
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
