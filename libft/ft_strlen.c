/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:27:42 by azaporoz          #+#    #+#             */
/*   Updated: 2018/03/23 14:49:31 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int				i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char*)s;
	while (*cs != '\0')
	{
		cs++;
		i++;
	}
	return (i);
}
