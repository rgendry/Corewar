/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:47:00 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/11 13:47:02 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_lennum(int num)
{
    int len;

    len = 0;
    if (num < 0)
        len++;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        len++;
        num /= 10;
    }
    return (len);
}