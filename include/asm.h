/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:25:26 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/17 18:56:35 by rgendry          ###   ########.fr       */
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

typedef struct              s_name
{
    char                    *name;
    int                     f_multi_lines_name;  // флаг для многострочного имя
}                           t_name;

typedef struct              s_com
{
    char                    *comment;
    int                     f_multi_lines_com; // флаг для многострочного коммента
}                           t_com;

typedef struct              s_champ
{
    char                    **file;
    int                     len_file;
    int                     num_lines_file; // надо ли? пока пусто
    struct s_com            *com;
    struct s_name           *name;
}                           t_champ;

/* parse */
void ft_parse(t_champ *champ, int i);
void ft_check_file_name(char *name);

/* complementary */
void ft_usage();
void ft_syntax_error(t_champ *champ);
void ft_error();
void    ft_initialization(t_champ *champ);

/* check_name */
void ft_parse_name(t_champ *champ, char *str, int i);

/* check_comment */
void ft_parse_com(t_champ *champ, char *str);

int		check_arg_type(char *str);
void	check_opertaions(char *str);
int	check_type2(char **token, int label);
int	check_type3(char **token, int label);
int	check_type4(char **token, int label);
int	check_type5(char **token, int label);
int	check_type6(char **token, int label);
int	check_type7(char **token, int label);
int	check_type8(char **token, int label);
int	check_type9(char **token, int label);

#endif
