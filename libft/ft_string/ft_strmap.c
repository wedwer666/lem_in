/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:32:27 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 19:50:27 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s != NULL && s != '\0' && f != NULL)
	{
		if (NULL != (str = ft_strnew(ft_strlen(s))))
		{
			while (s[i] != '\0')
			{
				str[i] = f(s[i]);
				i++;
			}
		}
	}
	return (str);
}
