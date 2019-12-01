/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2019/12/01 18:45:33 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_reader(t_champ *champ, int fd, char *str, char *buf)
{
    char *tmp;

    if (fd == -1)
        ft_usage();
    while ((get_next_line(fd, &buf)) > 0)
    {
        tmp = str;
        str = ft_strjoin(str, buf);
        free(tmp);
        tmp = str;
        str = ft_strjoin(str, "\n");
        ft_strdel(&tmp);
        ft_strdel(&buf);
    }
    champ->len_file = ft_strlen(str);
    champ->file = ft_strsplit(str, '\n');
    ft_strdel(&str);
    close(fd);
//    ft_print_matrix(champ->file);
}

int main(int argc, char **argv) {
    t_champ champ;
   /* char *str1;
    char *str2;
    char *strnew;

    *//*str1 = (char*)malloc(sizeof(char) * 3);
    str2 = (char*)malloc(sizeof(char) * 3);*//*
    str1 = "abc";
    str2 = "def";
    strnew = ft_memjoin(str1, str2, 3, 3);
    ft_printf("%s - %s - %s", str1, str2, strnew);*/
    if (argc != 2)
        ft_usage();
    ft_check_file_name(&champ, argv[1]);
    ft_initialization(&champ);
    ft_reader(&champ, open(argv[1], O_RDONLY), NULL, NULL);
    ft_parse(&champ, -1);
    ft_translation(&champ);
    ft_clear_everything(&champ, -1);
    return (0); // in the end will need to chang on exit
}
