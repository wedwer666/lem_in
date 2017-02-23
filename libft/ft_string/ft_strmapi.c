/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:27:26 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 19:50:59 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s != NULL && *s != '\0' && f != NULL)
	{
		if (NULL != (str = ft_strnew(ft_strlen(s))))
		{
			while (s[i] != '\0')
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
