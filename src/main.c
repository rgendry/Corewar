/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:29:46 by rgendry           #+#    #+#             */
/*   Updated: 2020/01/19 16:46:37 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_reader(t_champ *champ, int fd, char *str, char *buf)
{
	char	*tmp;
	int		ret;

	ret = 0;
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
	champ->len_file = ft_strlen(str);
	champ->file_str = str;
	ft_strdel(&buf);
	close(fd);
}

int		main(int argc, char **argv)
{
	t_champ	champ;

	if (argc != 2)
		ft_usage();
	ft_check_file_name(&champ, argv[1]);
	ft_initialization(&champ);
	ft_reader(&champ, open(argv[1], O_RDONLY), NULL, NULL);
	ft_parse(&champ, 0);
	ft_translation(&champ);
	ft_clear_everything(&champ);
	return (0);
}
