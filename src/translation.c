/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:07:53 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/25 15:48:44 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_translation(t_champ *champ)
{
    ft_magic_header(champ, -1);
<<<<<<< HEAD
    //ft_printf("%s - %d", champ->byte_code, ft_strlen((char*)champ->byte_code));
    // ft_name_to_byte(champ, -1);
    ft_assembly(champ); //тут будет сборка всех частей в общую строку байт кода
}
=======
    ft_assembly(champ);
    if ((champ->fd_byte = open("byte_code", O_WRONLY, O_CREAT)) == -1)
        ft_error(); // in the end
    write(champ->fd_byte, champ->byte_code, ft_strlen(champ->byte_code));
}
>>>>>>> 22878d7a7ca2f1e56f52775f930cb3d9a53d2fbc
