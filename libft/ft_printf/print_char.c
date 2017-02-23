/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:50:14 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/10 15:57:08 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_stdio.h"

int		print_char(va_list *va, t_flag fl)
{
	char	ch;
	int		size;
	char	*buff;

	ch = (char)va_arg(*va, int);
	size = fl.len - 1;
	size = size < 0 ? 0 : size;
	buff = (char*)ft_memset(ft_strnew(size), (fl.minus ? ' ' : fl.blank), size);
	!fl.minus ? FT_PUTSTR(buff) : FT_PUTCHAR(ch);
	!fl.minus ? FT_PUTCHAR(ch) : FT_PUTSTR(buff);
	ft_strdel(&buff);
	return (size + 1);
}
