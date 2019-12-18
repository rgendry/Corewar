/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:11:43 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 16:08:16 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_itoa_hex(long long int n, char sym)
{
	int							len;
	unsigned long long int		number;
	char						*result;
	char						*a;

	a = (sym == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	len = n < 0 ? 8 : ft_lennum_hex(n);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	number = n;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[len - 1] = a[number % 16];
		number /= 16;
		len--;
	}
	return (result);
}
