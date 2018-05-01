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

//#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (write(1, "error\n", 6));
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
	}
	close(fd);
}





/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			i = 0;
			fd = open(argv[1], O_RDONLY);
			while((ret = get_next_line(fd, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd);
       	}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
 	int fd2;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			i = 0;
			fd = open(argv[1], O_RDONLY);
			while((ret = get_next_line(fd, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd);
			i = 0;
			fd2 = open(argv[2], O_RDONLY);
			while((ret = get_next_line(fd2, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd2);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
 	int fd2;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			fd = open(argv[1], O_RDONLY);
			fd2 = open(argv[2], O_RDONLY);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line1>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line1>%s\n", ret, line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line2>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line2>%s\n", ret, line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line3>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line3>%s\n", ret, line);
			close(fd);
			close(fd2);
		}
	}
	return (1);
}
*/