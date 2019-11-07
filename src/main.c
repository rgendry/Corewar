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

void ft_reader(char *name, t_champ *champ)
{
    int fd;
    int ret;
    char *buf;

    if (!(buf = ft_memalloc(50000)))
        ft_error();
    fd = open(name, O_RDONLY);
    while ((ret = read(fd, buf, 50000)) < 0)
        ft_error();
    champ->len_file = ret; // вместо ft_strlen
    champ->file = ft_strsplit(buf, '\n');
    ft_strdel(&buf);
    close(fd);
}

int main(int argc, char **argv) {
    t_champ champ;

    if (argc != 2)
        ft_usage();

    ft_check_name(argv[1]);
    ft_reader(argv[1], &champ);
    ft_parse(&champ, -1);
    return 0;
}
