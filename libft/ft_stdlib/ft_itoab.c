/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:47:08 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/11 17:43:05 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		valid_dates(const char *base)
{
	if (ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	while (*base++ != '\0')
		if (NULL != (ft_strchr(base, *(base - 1))))
			return (0);
	return (1);
}

static void		rec(intmax_t n, const char *base, char *str, int *i)
{
	int		size;

	if (n == 0)
		return ;
	size = (int)ft_strlen(base);
	rec(n / size, base, str, i);
	str[(*i)++] = base[ft_abs(n % size)];
}

char			*ft_itoab(intmax_t value, const char *base, int sign)
{
	char	str[70];
	int		i;

	if (NULL == base || !valid_dates(base))
		return (NULL);
	i = 0;
	if (value < 0 || sign)
		str[i++] = value < 0 ? '-' : '+';
	if (value == 0)
		str[i++] = '0';
	rec(value, base, str, &i);
	str[i] = '\0';
	return (ft_strdup(str));
}
