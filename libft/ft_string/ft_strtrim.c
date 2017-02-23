/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:34:58 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 20:18:26 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctype.h"
#include "ft_string.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		begin;
	int		size;
	int		i;

	begin = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (0 == (size = ft_strlen(s)))
		return (ft_strdup(""));
	while (ft_isspace(s[size - 1]))
		if (--size == 0)
			return (ft_strdup(""));
	while (ft_isspace(s[begin]))
		begin++;
	if (NULL != (str = ft_strnew(size - begin)))
		while (begin != size)
			str[i++] = s[begin++];
	return (str);
}
