/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:56:20 by azaporoz          #+#    #+#             */
/*   Updated: 2018/04/25 19:22:37 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int		fd;
	int 	fd2;
	char	*line;
	char	*line2;
	int tr;

	tr = 0;
	if (ac == 1)
	{
		ft_putstr("error input_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (write(1, "1error\n", 7));
	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		return (write(1, "2error\n", 7));
	/*
	while ((get_next_line(fd, &line) == 1) || (get_next_line(fd2, &line2) == 1))
	{
			ft_putendl(line);
			ft_putendl(line2);
	}
	*/
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd2, &line2);
	ft_putendl(line2);

	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd2, &line2);
	ft_putendl(line2);

	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd2, &line2);
	ft_putendl(line2);


	close(fd);
	close(fd2);
	return (1);
}
