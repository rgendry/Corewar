/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:25:26 by rgendry           #+#    #+#             */
/*   Updated: 2020/01/21 19:21:55 by rgendry          ###   ########.fr       */
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

typedef struct				s_arg
{
	unsigned char			*byte_code;
	int						weight;
}							t_arg;

typedef struct				s_instr
{
	unsigned char			instr;
	unsigned char			type;
	struct s_arg			*arg1;
	struct s_arg			*arg2;
	struct s_arg			*arg3;
	int						weight;
	struct s_instr			*next;
}							t_instr;

typedef struct				s_label
{
	char					*name;
	int						place;
	struct s_label			*next;
}							t_label;

typedef struct				s_tokens
{
	char					**token;
	struct s_tokens			*next;
}							t_tokens;

typedef struct				s_name
{
	unsigned char			*name;
	int						cur_len;
	int						f_multi_lines_name;
}							t_name;

typedef struct				s_com
{
	unsigned char			*comment;
	int						cur_len;
	int						f_multi_lines_com;
}							t_com;

typedef struct				s_champ
{
	int						all_weight;
	char					*file_str;
	int						len_file;
	unsigned char			*exec_size;
	int						num_lines_file;
	struct s_com			*com;
	struct s_instr			*byte_code;
	struct s_name			*name;
	struct s_label			*labels;
	struct s_tokens			*string;
	unsigned char			*instr_byte;
	int						instr_byte_len;
	unsigned char			*byte_c;
	unsigned char			*m_header;
	unsigned char			*four_zero_bytes;
	char					*file_name_cor;
}							t_champ;

char						*ft_strndup(const char *s1, size_t n);
int							ft_lennum(int num);
char						*ft_itoa_hex(long long int n, char sym);
int							ft_lennum_hex(long long int num);
void						ft_putnbr_hex_fd(int n, int fd);
void						ft_parse(t_champ *champ, int i);
void						ft_check_file_name(t_champ *champ, char *name);
void						ft_initialization(t_champ *champ);
int							ft_check_cmd_string(t_champ *champ, char *str,
								int i, char cmd);
int							is_emptystr(char *str);
int							is_comment(char *str);
int							arr_len(char **arr);
void						free_nodes(t_label **nodes);
void						free_arr(char ***arr);
void						ft_clear_everything(t_champ *champ);
void						ft_usage();
void						ft_syntax_error(t_champ *champ);
void						ft_lex_error(t_champ *champ);
void						ft_error(t_champ *champ);
void						ft_errors(t_champ *champ);
void						ft_too_long_com(t_champ *champ);
void						ft_too_long_name(t_champ *champ);
void						ft_parse_name(t_champ *champ, char *str);
void						ft_parse_com(t_champ *champ, char *str);
void						ft_check_end(t_champ *champ, char *str, int i);
void						ft_create_com(t_champ *champ);
char						*spaces(char *str, int i, int j, char *new);
int							check_arg_type(char *str);
t_tokens					*check_operations(t_champ *champ, char *str);
int							check_op_type(t_champ *champ, char *str,
								char **token, int label);
int							check_type2(char **token, int label);
int							check_type3(char **token, int label);
int							check_type4(char **token, int label);
int							check_type5(char **token, int label);
int							check_type6(char **token, int label);
int							check_type7(char **token, int label);
int							check_type8(char **token, int label);
int							check_type9(char **token, int label);
int							is_label(char *str);
t_label						*create_label(t_champ *champ, char *data);
int							add_label(t_label **head, t_label *new);
int							find_label(t_champ *champ, char *str);
void						ft_magic_header(t_champ *champ);
int							ft_assembly(t_champ *champ);
void						ft_cycle(t_champ *champ);
void						ft_translation(t_champ *champ);
unsigned char				operation_type(t_champ *champ, char *str);
t_instr						*instruction_to_byte(t_champ *champ, char **token,
								int label, t_instr *byte_code);
unsigned char				*reg_to_byte(t_champ *champ, char *str);
unsigned char				*dir_to_byte(t_champ *champ, char *str, int type);
unsigned char				*indir_to_byte(t_champ *champ, char *str);
void						ft_exec_to_byte(t_champ *champ);
unsigned char				*ft_memjoin(unsigned char *s1, unsigned char *s2,
								int len1, int len2);
int							ft_count_weight(t_champ *champ, char **token,
								int label);
void						ft_count_current_weight(t_instr *byte_code);
int							ft_arg_weight(char *str, int type);
int							ft_numln(char *str);
int							check_minus(char **token);
void						del_label(t_label **labels, char **token);

#endif
