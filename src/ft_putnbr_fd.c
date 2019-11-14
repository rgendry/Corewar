/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:30:34 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/13 14:30:43 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long int	ft_discharge(int n)
{
    long int	res;

    res = 1;
    while (n / 10)
    {
        res *= 10;
        n /= 10;
    }
    return (res);
}

void	ft_putnbr_hex_fd(int n, int fd)
{
    long int	discharge;
    long int	tmp_n;
    char		c;

    tmp_n = n;
    discharge = ft_discharge(n);
    if (tmp_n < 0)
    {
        ft_putchar_fd('-', fd);
        tmp_n *= -1;
    }
    while (discharge || tmp_n)
    {
        c = tmp_n / discharge + '0';
        ft_putchar_fd(c, fd);
        tmp_n %= discharge;
        discharge /= 10;
    }
}
