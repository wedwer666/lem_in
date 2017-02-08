/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:08:17 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/07 12:55:51 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_wchar(va_list *va, t_flag fl)
{
	wint_t	wch;
	int		size;
	char	*buff;
	int		nr_bits;

	wch = va_arg(*va, wint_t);
	nr_bits = ft_wbits(wch);
	size = fl.len - nr_bits;
	size = size < 0 ? 0 : size;
	buff = (char*)ft_memset(ft_strnew(size), (fl.minus ? ' ' : fl.blank), size);
	size += nr_bits;
	!fl.minus ? FT_PUTSTR(buff) : FT_PUTWCHAR(wch);
	!fl.minus ? FT_PUTWCHAR(wch) : FT_PUTSTR(buff);
	ft_strdel(&buff);
	return (size);
}
