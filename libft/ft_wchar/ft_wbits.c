/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wbits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:16:02 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/07 14:07:06 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

int		ft_wbits(wchar_t wch)
{
	if (wch <= 0x7F)
		return (1);
	else if (wch <= 0x7FF)
		return (2);
	else if (wch <= 0xFFFF)
		return (3);
	else if (wch <= 0x10FFFF)
		return (4);
	return (0);
}
