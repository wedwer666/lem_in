/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:13:20 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/24 12:51:29 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_ctype.h"

int		ft_isnbr(const char *str)
{
	int		tmp;
	int		sign;

	sign = (('-' == *str) ? -1 : 1);
	(('-' == *str) ? str++ : 0);
	tmp = 0;	
	if (!ft_isdigit(*str) || ft_strlen(str) > 10)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if (tmp < 0 && (tmp * 10 - (*str - '0')) > 0)
			return (0);
		else if (tmp > 0 && (tmp * 10 + (*str - '0')) < 0)
			return (0);
		tmp = tmp * 10 + sign * (*str - '0');
		str++;
	}
	return (1);
}
