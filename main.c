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

#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		free(line);
	}
	close(fd);
}
