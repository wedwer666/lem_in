/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:25:04 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 18:29:35 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

static	char	*pass_exceptions(char const *s1, char const *s2)
{
	char	*temp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (NULL != (temp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		temp[0] = '.';
	return (temp);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = pass_exceptions(s1, s2);
	if (NULL != str)
	{
		if (0 != ft_strlen(str))
		{
			ft_strcpy(str, s1);
			j = ft_strlen(s1);
			while (s2[i] != '\0')
				str[j++] = s2[i++];
		}
	}
	return (str);
}
