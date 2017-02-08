/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:46:42 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/26 19:14:18 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	if (*s == '\0')
	{
		if (NULL != (copy = (char*)ft_memalloc(sizeof(char))))
			copy[0] = '\0';
	}
	else if (NULL != (copy = ft_strnew(ft_strlen(s))))
		ft_strcpy(copy, s);
	return (copy);
}
