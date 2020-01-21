/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:52:39 by ubartemi          #+#    #+#             */
/*   Updated: 2020/01/19 16:29:03 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_assembly(t_champ *champ)
{
	unsigned char	*tmp;

	champ->byte_c = ft_memjoin(champ->m_header, champ->name->name, 4, 128);
	tmp = champ->byte_c;
	champ->byte_c = ft_memjoin(champ->byte_c, champ->four_zero_bytes, 132, 4);
	free(tmp);
	tmp = champ->byte_c;
	champ->byte_c = ft_memjoin(champ->byte_c, champ->exec_size, 136, 4);
	free(tmp);
	tmp = champ->byte_c;
	champ->byte_c = ft_memjoin(champ->byte_c, champ->com->comment, 140, 2048);
	free(tmp);
	tmp = champ->byte_c;
	champ->byte_c = ft_memjoin(champ->byte_c, champ->four_zero_bytes, 2188, 4);
	free(tmp);
	tmp = champ->byte_c;
	champ->byte_c = ft_memjoin(champ->byte_c, champ->instr_byte, 2192,
			champ->instr_byte_len);
	free(tmp);
	return (2192 + champ->instr_byte_len);
}
