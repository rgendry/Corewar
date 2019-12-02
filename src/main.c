/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2019/11/18 17:11:28 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_reader(t_champ *champ, int fd, char *str, char *buf)
{
    char *tmp;
    int ret;

    ret  = 0;
    if (fd == -1)
        ft_usage();
    buf = ft_memalloc(100);
    while ((ret = read(fd, buf, 99)) > 0)
    {
        tmp = str;
        buf[ret] = '\0';
        str = ft_strjoin(str, buf);
        ft_strdel(&tmp);
    }
/*    while ((get_next_line(fd, &buf)) > 0)
    {
        tmp = str;
        str = ft_strjoin(str, buf);
        free(tmp);
        tmp = str;
        str = ft_strjoin(str, "\n");
        ft_strdel(&tmp);
        ft_strdel(&buf);
    }*/
    champ->len_file = ft_strlen(str);
    champ->file_str = str;
    ft_strdel(&buf);
    close(fd);
}
//
//void    print_strings(t_champ *champ)
//{
//    int i;
//
//    i = 0;
//    while (champ->string)
//    {
//        while (champ->string->token[i])
//        {
//            ft_printf("%s - ", champ->string->token[i]);
//            i++;
//        }
//        i = 0;
//        ft_printf("\n");
//        champ->string = champ->string->next;
//    }
//}

int main(int argc, char **argv) {
    t_champ champ;

    if (argc != 2)
        ft_usage();
    ft_check_file_name(&champ, argv[1]);
    ft_initialization(&champ);
    ft_reader(&champ, open(argv[1], O_RDONLY), NULL, NULL);
    ft_parse(&champ, 0);
    ft_translation(&champ);
    ft_clear_everything(&champ);
   // ft_strdel(&strnew);
    return (0); // in the end will need to chang on exit
}
