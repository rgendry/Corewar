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

#include "../include/asm.h"

void ft_usage()
{
    printf("Put one argument (file name)");
    exit (1);
}

void ft_error()
{
    printf("Error");
    exit (1);
}

char *ft_reader(char *name)
{
    int fd;
    int ret;
    char *buf;
    
    buf = (char*)malloc(sizeof(char) * 5000);
    fd = open(name, O_RDONLY);
    while ((ret = read(fd, buf, 5000)) < 0)
        ft_error();
    return (buf);
}

int main(int argc, char **argv) {
    char *file;
    if (argc != 2)
        ft_usage();
    
    file = ft_reader(argv[1]);
    ft_parse(file, -1);
    return 0;
}
