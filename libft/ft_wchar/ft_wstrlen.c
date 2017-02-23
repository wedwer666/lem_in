/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 13:04:30 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/28 13:44:44 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

size_t	ft_wstrlen(const wchar_t *wcs)
{
	size_t	size;

	size = 0;
	while (*wcs)
	{
		if (*wcs < 0x7F)
			size++;
		else if (*wcs < 0x7FF)
			size += 2;
		else if (*wcs < 0xFFFF)
			size += 3;
		else if (*wcs <= 0x10FFFF)
			size += 4;
		wcs++;
	}
	return (size);
}
