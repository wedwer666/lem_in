/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:51:44 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/10 15:57:03 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_stdio.h"

int			print_str(va_list *va, char ch, t_flag fl)
{
	char	*str;
	char	*buff;
	int		size;

	if (ch == 'c')
		return (print_char(va, fl));
	str = (char*)va_arg(*va, int*);
	str = (str == NULL ? ft_strdup("(null)") : ft_strdup(str));
	if (fl.prec && (fl.prec - 1 < (int)ft_strlen(str)))
		str[fl.prec - 1] = '\0';
	size = fl.len - ft_strlen(str);
	size = size < 0 ? 0 : size;
	size += fl.prec < (int)ft_strlen(str) ? fl.prec : 0;
	buff = (char*)ft_memset(ft_strnew(size), (fl.minus ? ' ' : fl.blank), size);
	size += ft_strlen(str);
	!fl.minus ? FT_PUTSTR(buff) : FT_PUTSTR(str);
	!fl.minus ? FT_PUTSTR(str) : FT_PUTSTR(buff);
	ft_strdel(&str);
	ft_strdel(&buff);
	return (size);
}
