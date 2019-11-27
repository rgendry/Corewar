

# include "asm.h "

char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    char	*str;

    if (s1 == NULL && s2 == NULL)
        return (ft_strnew(0));
    else if (s1 == NULL)
        return (ft_strdup(s2));
    else if (s2 == NULL)
        return (ft_strdup(s1));
    i = 0;
    str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (!str)
        return (NULL);
    while (*s1)
    {
        str[i++] = *s1;
        s1++;
    }
    while (*s2)
    {
        str[i++] = *s2;
        s2++;
    }
    str[i] = '\0';
    return (str);
}