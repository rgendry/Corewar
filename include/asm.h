/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:25:26 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/04 18:36:03 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "op.h"

typedef struct  s_champ
{
    char        **file;
    int         len_file;
    int         num_lines_file; // надо ли? пока пусто
    int         f_multi_lines_name;  // флаг для многострочного имя
    int         f_multi_lines_com; // флаг для многострочного коммента
}               t_champ;

/* parse */
void ft_parse(t_champ *champ, int i);
void ft_check_name(char *name);

/* complementary */
void ft_usage();
void ft_error();
#endif
