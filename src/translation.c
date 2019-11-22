/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/13 14:07:55 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_translation(t_champ *champ)
{
    ft_magic_header(champ, -1);
    ft_assembly(champ);
    if ((champ->fd_byte = open("byte_code", O_WRONLY, O_CREAT)) == -1)
        ft_error(); // in the end
    write(champ->fd_byte, champ->byte_code, ft_strlen(champ->byte_code));
}