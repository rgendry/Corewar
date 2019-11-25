/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:25:26 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/25 15:44:21 by rgendry          ###   ########.fr       */
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

typedef struct          s_instr
{
    char                instr;
    char                type;
    char                *arg1;
    char                *arg2;
    char                *arg3;
    struct s_instruct   *next;
}                       t_instr;

typedef struct  s_label
{
    char            *name;
    int             place;
    struct s_label  *next;
}                   t_label;

typedef struct              s_name
{
    char                    *name;
    int                     len_name;
    int                     f_multi_lines_name;
}                           t_name;

typedef struct              s_com
{
    char                    *comment;
    int                     len_com;
    int                     f_multi_lines_com;
}                           t_com;

typedef struct              s_champ
{
    int                     start_instr;
    char                    **file;
    int                     len_file;
    int                     num_lines_file;
    struct s_com            *com;
    struct s_name           *name;
    struct s_label          *labels;
    int                     fd_byte;
    char                    *byte_code;
    char                    *m_header;
    char                    *four_zero_bytes;
    char                    *file_name_cor;
}                           t_champ;

/* separate function */
char	*ft_strndup(const char *s1, size_t n);
int		ft_lennum(int num);
char	*ft_itoa_hex(long long int n, char sym);
int	    ft_lennum_hex(long long int num);
void	ft_putnbr_hex_fd(int n, int fd);

/* parse */
void ft_parse(t_champ *champ, int i);
void ft_check_file_name(t_champ *champ, char *name);

/* complementary */
void ft_initialization(t_champ *champ);
void ft_print_matrix(char **matrix); // will need to delete this function
int ft_check_cmd_string(t_champ *champ, char *str,int i, char CMD);
int is_emptystr(char *str);
int is_comment(char *str);

/* cleaning */
void free_nodes(t_label **nodes);
void free_arr(char ***arr);
void ft_clear_everything(t_champ *champ, int i);

/* errors */
void ft_usage();
void ft_syntax_error(t_champ *champ);
void ft_error();
void ft_errors(t_champ *champ);

/* check_name */
void ft_parse_name(t_champ *champ, char *str);

/* check_comment */
void ft_parse_com(t_champ *champ, char *str);


/* check instr */
int		check_arg_type(char *str);
void	check_opertaions(t_champ *champ, char *str);
int	check_type2(char **token, int label);
int	check_type3(char **token, int label);
int	check_type4(char **token, int label);
int	check_type5(char **token, int label);
int	check_type6(char **token, int label);
int	check_type7(char **token, int label);
int	check_type8(char **token, int label);
int	check_type9(char **token, int label);

int		check_label(char *str);
t_label	*create_label(char	*data);
int	    add_label(t_label **head, t_label *new);
int	arr_len(char **arr);



/* magic_header_to_byte */
void ft_magic_header(t_champ *champ, int i);

/* assembly */
void ft_assembly(t_champ *champ);

/* translation */
void ft_translation(t_champ *champ);
#endif
