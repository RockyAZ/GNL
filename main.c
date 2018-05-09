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
//	int 	fd1;
//	int 	fd2;
//	int 	fd3;
	char	*line;
//	char	*line1;
//	char	*line2;
//	char	*line3;
	int tr;

	tr = 0;
	if (ac == 1)
	{
		ft_putstr("error input_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (write(1, "0error\n", 7));

/*	if ((fd1 = open(av[2], O_RDONLY)) == -1)
		return (write(1, "1error\n", 7));
	if ((fd2 = open(av[3], O_RDONLY)) == -1)
		return (write(1, "2error\n", 7));
	if ((fd3 = open(av[4], O_RDONLY)) == -1)
		return (write(1, "3error\n", 7));
*/

//write(1, "a\n", 2);
	while ((tr = get_next_line(fd, &line)) == 1)
	{
//write(1, "b\n", 2);
//			printf("TR-%d\n", tr);

			ft_putendl(line);
//			printf("%d\n", *line);
	}
//	printf("TR:%d\n", tr);
	close(fd);


/*
	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);

*/
/*
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd1, &line1);
	ft_putendl(line1);
	get_next_line(fd2, &line2);
	ft_putendl(line2);
	get_next_line(fd3, &line3);
	ft_putendl(line3);

	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd1, &line1);
	ft_putendl(line1);
	get_next_line(fd2, &line2);
	ft_putendl(line2);
	get_next_line(fd3, &line3);
	ft_putendl(line3);


	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
*/

/*
	get_next_line(fd, &line);
	if (strcmp(line, "aaa") == 0)
		ft_putendl(line);
	get_next_line(fd1, &line1);
	if(strcmp(line1, "111") == 0)
		ft_putendl(line1);
	get_next_line(fd2, &line2);
	if(strcmp(line2, "www") == 0)
		ft_putendl(line2);
	get_next_line(fd3, &line3);
	if(strcmp(line3, "888") == 0)
		ft_putendl(line3);

	tr = get_next_line(fd, &line);
	if(strcmp(line, "bbb") == 0)
		ft_putendl(line);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd1, &line1);
	if((tr = strcmp(line1, "222") == 0))
		ft_putendl(line1);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd2, &line2);
	if(strcmp(line2, "zzz") == 0)
		ft_putendl(line2);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd3, &line3);
	if(strcmp(line3, "999") == 0)
		ft_putendl(line3);
//printf("tr-%d\n", tr);
//printf("------------------------------\n");
	tr = get_next_line(fd, &line);
		ft_putendl(line);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd1, &line1);
		ft_putendl(line1);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd2, &line2);
		ft_putendl(line2);
//printf("tr-%d\n", tr);
	tr = get_next_line(fd3, &line3);
		ft_putendl(line3);
//printf("tr-%d\n", tr);


	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);

*/
	return (0);
}
