/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:27:40 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/26 19:06:00 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

static int		valid_dates(const char *base)
{
	if (ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	while (*base++ != '\0')
		if (NULL != (ft_strchr(base, *(base - 1))))
			return (0);
	return (1);
}

static void		rec(uintmax_t n, const char *base, char *str, int *i)
{
	int		size;

	size = (int)ft_strlen(base);
	if (n == 0)
		return ;
	rec(n / size, base, str, i);
	str[(*i)++] = base[n % size];
}

char			*ft_utoab(uintmax_t value, const char *base)
{
	char	str[70];
	int		i;

	if (NULL == base || !valid_dates(base))
		return (NULL);
	i = 0;
	if (value == 0)
		str[i++] = '0';
	rec(value, base, str, &i);
	str[i] = '\0';
	return (ft_strdup(str));
}
