/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:12:33 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/28 08:46:29 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_other(char ch, t_flag fl)
{
	char	*buff;
	int		size;

	size = fl.len;
	size = fl.len > 1 ? fl.len - 1 : 0;
	buff = (char*)ft_memset(ft_strnew(size), (fl.minus ? ' ' : fl.blank), size);
	fl.minus ? FT_PUTCHAR(ch) : FT_PUTSTR(buff);
	fl.minus ? FT_PUTSTR(buff) : FT_PUTCHAR(ch);
	ft_strdel(&buff);
	return (++size);
}
