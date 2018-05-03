/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:08:07 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/03 15:26:16 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//BUFF_SIZE == 1
int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];

	if (argc > 2)
		ft_putstr("Too many arguments.");
	else if (argc < 2)
		ft_putstr("File name missing.");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
            printf("%d", ret);
			buf[ret] = '\0';
			ft_putstr(buf);
//            printf("%d", ret);
        }
		close(fd);
	}
	return (0);
}
