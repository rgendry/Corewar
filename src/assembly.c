/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:52:39 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 15:38:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_assembly(t_champ *champ)
{
	unsigned char	*tmp;

	champ->byte_code_all = ft_memjoin(champ->m_header, champ->name->name, 4, 128);
	tmp = champ->byte_code_all;
	champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->four_zero_bytes, 132, 4);
	free(tmp);
	tmp = champ->byte_code_all;
	champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->exec_size, 136, 4);
	free(tmp);
	tmp = champ->byte_code_all;
	champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->com->comment, 140, 2048);
	free(tmp);
	tmp = champ->byte_code_all;
	champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->four_zero_bytes, 2188, 4);
	free(tmp);
	tmp = champ->byte_code_all;
	champ->byte_code_all = ft_memjoin(champ->byte_code_all, champ->instr_byte, 2192, champ->instr_byte_len);
	free(tmp);
	return (2192 + champ->instr_byte_len);
}
