#include "../include/asm.h"

void ft_parse_com(char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\n')
    {
        write(1, &str[i], 1);
    }
}

//void ft_parse_name(char *str)
//{
//
//}

void ft_check_str(char *str)
{
//    if (ft_strstr(NAME_CMD_STRING, str))
//        ft_parse_name(str);
     if (ft_strstr(COMMENT_CMD_STRING, str))
        ft_parse_com(str);
}

void ft_parse(char *file, int i)
{
    int start;
    char *tmp;

    start = 0;
    while (++i < (int)ft_strlen(file))
    {
        if (file[i] == '\n')
        {
            tmp = (char*)malloc(sizeof(char) * (i - start) + 1);
            strlcpy(tmp, file + start, i);
            ft_check_str(tmp);
            start += i;
            ft_strdel(&tmp);
        }
    }
}
