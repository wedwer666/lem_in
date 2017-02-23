/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:22:20 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 15:53:30 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*temp;
	size_t			i;

	i = 0;
	temp = (const char*)s;
	while (i != n)
		if ((unsigned char)temp[i++] == (unsigned char)c)
			return ((void *)(temp + i - 1));
	return (NULL);
}
