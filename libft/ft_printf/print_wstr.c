/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:09:43 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/06 16:46:13 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t poz)
{
	if (precision <= 0)
		return (poz);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, poz + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, poz + 1));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, poz + 1));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, poz + 1));
	else
		return (poz);
}

int				print_wstr(va_list *va, char ch, t_flag fl)
{
	wchar_t	*wstr;
	char	*buff;
	int		size;

	if (ft_strchr("cC", ch))
		return (print_wchar(va, fl));
	wstr = (ft_strchr("sS", ch) ? va_arg(*va, wchar_t*) : ft_wstrnew(2));
	wstr = (wstr == NULL ? ft_wstrdup(L"(null)") : ft_wstrdup(wstr));
	if (fl.prec && (fl.prec - 1 < (int)(ft_wstrlen(wstr))))
		wstr[calc_wstrlen(wstr, fl.prec - 1, 0)] = L'\0';
	size = fl.len - ft_wstrlen(wstr);
	size = size < 0 ? 0 : size;
	size += fl.prec < (int)ft_wstrlen(wstr) ? fl.prec : 0;
	buff = (char*)ft_memset(ft_strnew(size), (fl.minus ? ' ' : fl.blank), size);
	size += ft_wstrlen(wstr);
	!fl.minus ? FT_PUTSTR(buff) : FT_PUTWSTR(wstr);
	!fl.minus ? FT_PUTWSTR(wstr) : FT_PUTSTR(buff);
	ft_wstrdel(&wstr);
	ft_strdel(&buff);
	return (size);
}
