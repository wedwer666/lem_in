/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:04:31 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 20:30:35 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

static long long	rec(const char *str, long long val, int sign)
{
	if (!ft_isdigit(*str))
		return (val);
	return (rec(str + 1, val * 10 + sign * (*str - '0'), sign));
}

long long			ft_atoll(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		return (rec(str + 1, 0, -1));
	else if (*str == '+')
		return (rec(str + 1, 0, 1));
	else
		return (rec(str, 0, 1));
}
