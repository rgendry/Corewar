/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:37:25 by ubartemi          #+#    #+#             */
/*   Updated: 2019/11/07 14:37:27 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_parse_com(t_champ *champ, char *str)
{
    ft_printf("%s\n%d\n", str, champ->len_file);
    exit(0);
}