/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_header_to_byte.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:31:32 by ubartemi          #+#    #+#             */
/*   Updated: 2019/12/18 20:30:12 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_find_shift(int len_m_header)
{
	if (len_m_header == 8 || len_m_header == 7)
		return (24);
	else if (len_m_header == 6 || len_m_header == 5)
		return (16);
	else if (len_m_header == 4 || len_m_header == 3)
		return (8);
	else
		return (0);
}

void	ft_magic_header(t_champ *champ)
{
	int	shift;
	int	j;
	int	len_m_header;

	len_m_header = ft_lennum_hex(COREWAR_EXEC_MAGIC);
	shift = 0;
	j = len_m_header % 2 == 0 ? len_m_header / 2 : (len_m_header / 2) + 1;
	if (!(champ->m_header = ft_memalloc(4)))
		ft_error(champ);
	while (j)
	{
		champ->m_header[j--] = (COREWAR_EXEC_MAGIC >> shift) & 255;
		shift += 8;
	}
}
