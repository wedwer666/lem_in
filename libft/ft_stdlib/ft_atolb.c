/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:57:22 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 21:12:25 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctype.h"
#include "ft_string.h"

static int		valid_dates(const char *str, const char *base)
{
	const char	*base_tmp;

	base_tmp = base;
	if (ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	while (*base_tmp++ != '\0')
		if (NULL != ft_strchr(base_tmp, *(base_tmp - 1)))
			return (0);
	while (*str++ != '\0')
		if (NULL == ft_strchr(base, *str))
			return (0);
	return (1);
}

static long		rec(const char *str, const char *base, long val, int sign)
{
	size_t	i;

	i = -1;
	while (++i != ft_strlen(base))
		if (*str == base[i])
			return (rec(str + 1, base, val * ft_strlen(base) + sign * i, sign));
	return (val);
}

long			ft_atolb(const char *str, const char *base)
{
	if (!valid_dates(str, base))
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		return (rec(str + 1, base, 0, -1));
	if (*str == '+')
		return (rec(str + 1, base, 0, 1));
	return (rec(str, base, 0, 1));
}
