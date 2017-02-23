/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:35:50 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 20:04:07 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strrev(const char *str)
{
	char	*rev;
	size_t	size;
	size_t	i;

	rev = NULL;
	if (NULL != (rev = ft_strnew(ft_strlen(str))))
	{
		size = ft_strlen(str);
		i = 0;
		while (i != size)
		{
			rev[i] = str[size - i - 1];
			i++;
		}
	}
	return (rev);
}
