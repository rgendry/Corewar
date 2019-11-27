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

char	*ft_strjoin_se(char const *s1, char const *s2)
{
    int		i;
    char	*str;

    if (s1 == NULL && s2 == NULL)
        return (ft_strnew(0));
    else if (s1 == NULL)
        return (ft_strdup(s2));
    else if (s2 == NULL)
        return (ft_strdup(s1));
    i = 0;
    str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (!str)
        return (NULL);
    while (*s1)
    {
        str[i++] = *s1;
        s1++;
    }
    while (*s2)
    {
        str[i++] = *s2;
        s2++;
    }
    str[i] = '\0';
    return (str);
}
