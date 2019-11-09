/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/04 18:37:07 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_reader(t_champ *champ, int fd, char *str, char *buf)
{
    char *tmp;

    while ((get_next_line(fd, &buf)) > 0)
    {
        tmp = str;
        str = ft_strjoin(str, buf);
        free(tmp);
        tmp = str;
        str = ft_strjoin(str, "\n");
        free(tmp);
        free(buf);
    }
    champ->len_file = ft_strlen(str);
    champ->file = ft_strsplit(str, '\n');
    ft_strdel(&str);
    close(fd);
//    ft_print_matrix(champ->file);
}

int main(int argc, char **argv) {
    t_champ champ;

    if (argc != 2)
        ft_usage();
    ft_check_file_name(argv[1]);
    ft_initialization(&champ);
    ft_reader(&champ, open(argv[1], O_RDONLY), NULL, NULL);
    ft_parse(&champ, -1);
    free(champ.file); // need function for clear everything
    ft_clear_everything(&champ);
    exit (0);
}
