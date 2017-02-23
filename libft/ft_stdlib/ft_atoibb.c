/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:09:05 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/11 20:33:40 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_ctype.h"

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

char		*ft_atoibb(const char *str, const char *fbase, const char *tbase)
{
	int		val;

	if (!valid_dates(fbase, tbase))
		return (NULL);
	val = ft_atoib(str, fbase);
	return (ft_itoab(val, tbase, 0));
}
