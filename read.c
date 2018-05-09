/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:08:07 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/09 17:34:13 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	char	*str;

	if (argc > 2)
		ft_putstr("Too many arguments.");
	else if (argc < 2)
		ft_putstr("File name missing.");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
        }
		printf("%s", str);
		printf("%d\n", ret);
		close(fd);
	}
	return (0);
}
