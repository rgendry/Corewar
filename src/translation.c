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
    if ((champ->fd_byte = open("byte_code", O_CREAT,O_WRONLY)) == -1)
        ft_error();
    ft_magic_header(champ, -1);
    //ft_printf("%s - %d", champ->byte_code, ft_strlen((char*)champ->byte_code));
    // ft_name_to_byte(champ, -1);
    ft_assembly(champ); //тут будет сборка всех частей в общую строку байт кода
}