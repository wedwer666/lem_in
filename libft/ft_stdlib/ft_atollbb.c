/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollbb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:23:00 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/11 20:34:38 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

static int	valid_dates(const char *fbase, const char *tbase)
{
	while (*fbase++ != '\0')
		if (NULL != ft_strchr(fbase, *(fbase - 1)))
			return (0);
	while (*tbase++ != '\0')
		if (NULL != ft_strchr(tbase, *(tbase - 1)))
			return (0);
	return (1);
}

char		*ft_atollbb(const char *str, const char *fbase, const char *tbase)
{
	long long	val;

	if (!valid_dates(fbase, tbase))
		return (NULL);
	val = ft_atollb(str, fbase);
	return (ft_itoab(val, tbase, 0));
}
