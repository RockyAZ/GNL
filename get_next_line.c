/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:05:31 by azaporoz          #+#    #+#             */
/*   Updated: 2018/04/26 19:25:19 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
int	get_next_line(const int fd, char **line)
{
	int ret;
	char buf[BUFF_SIZE];
	static char *pr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE - 1)))
	{
		pr = buf;
		while (*pr != '\n' && *pr != '\0')
		{
			ft_putchar(*pr);
			pr++;
		}
	}
	if (*pr == '\n')
		return (1);
	return (0);
}