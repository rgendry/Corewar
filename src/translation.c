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

void ft_magic_header(int fd)
{
    int len;
    char *m_header;

    len = ft_lennum_hex(COREWAR_EXEC_MAGIC);
    while (len++ < 8)
        write(fd, "0", 1);
    m_header =  ft_itoa_hex(COREWAR_EXEC_MAGIC, 'x');
    ft_putstr_fd(m_header, fd);
}

void ft_translation(t_champ *champ)
{
    if ((champ->fd_byte = open("byte_code", O_WRONLY, O_CREAT)) == -1)
        ft_error();
    ft_magic_header(champ->fd_byte);
//    ft_printf("%x\n", 110);
//    ft_putnbr_hex_fd(110, champ->fd_byte);
    ft_name_to_byte(champ, -1);
}