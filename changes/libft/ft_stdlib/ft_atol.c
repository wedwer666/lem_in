/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:54:18 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 21:11:59 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctype.h"

static long	rec(const char *str, int val, int sign)
{
	if (!ft_isdigit(*str))
		return (val);
	return (rec(str + 1, val * 10 + sign * (*str - '0'), sign));
}

long		ft_atol(const char *str)
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
