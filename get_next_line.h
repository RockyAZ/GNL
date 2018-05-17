/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:09:55 by azaporoz          #+#    #+#             */
/*   Updated: 2018/05/11 13:10:27 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define SIZE 4864
# include "libft/includes/libft.h"

typedef	struct	s_line
{
	int			err;
	int			fd;
}				t_line;

int				get_next_line(const int fd, char **line);
#endif
