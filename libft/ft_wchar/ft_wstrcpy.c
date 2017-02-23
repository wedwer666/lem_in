/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:38:48 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/28 14:54:43 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

wchar_t	*ft_wstrcpy(wchar_t *dest, const wchar_t *src)
{
	wchar_t	*tmp;

	tmp = dest;
	while (L'\0' != *src)
		*tmp++ = *src++;
	*tmp = L'\0';
	return (dest);
}
