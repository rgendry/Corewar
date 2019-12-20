/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:34:13 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 16:10:01 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*s2;
	unsigned int	counter;

	s2 = (char*)malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (NULL);
	counter = 0;
	while (s1[counter] && counter < n)
	{
		s2[counter] = s1[counter];
		counter++;
	}
	s2[counter] = '\0';
	return (s2);
}
