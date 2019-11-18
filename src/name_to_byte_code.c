/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_to_byte_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:53:04 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/11 12:53:05 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
//
//void ft_name_to_byte(t_champ *champ, int i)
//{
//    // need to redo it
//    char *in_hex;
//    char *name;
//    int len;
//
//    len = champ->name->len_name;
//    name = champ->name->name;
//    while (name[++i])
//    {
//        in_hex = ft_itoa_hex(name[i], 'x');
//        ft_putstr_fd(in_hex, champ->fd_byte);
//    }
//    while (len++ < PROG_NAME_LENGTH)
//        ft_putstr_fd("0", champ->fd_byte);
//}