/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:03:14 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 17:24:01 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	size;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		size = ft_strlen(s);
		if (NULL != (str = ft_strnew(len)))
			while (s[start] != '\0' && i != len)
				str[i++] = s[start++];
	}
	return (str);
}
