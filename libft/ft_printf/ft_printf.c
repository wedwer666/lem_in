/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:35:58 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/09 14:50:29 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"

int		convert(const char **format, va_list *va, t_flag fl)
{
	if (**format)
	{
		if (ft_strchr("dDioOuUxXp", **format))
			return (print_int(va, **format, fl));
		else if (ft_strchr("aAeEfFgG", **format))
			return (print_float(va, **format, fl));
		else if (ft_strchr("SC", **format)
				|| (ft_strchr("sc", **format) && L_FL == fl.mod_fl))
			return (print_wstr(va, **format, fl));
		else if (ft_strchr("sc", **format))
			return (print_str(va, **format, fl));
		else if (**format)
			return (print_other(**format, fl));
	}
	(*format)--;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	va;

	len = 0;
	va_start(va, format);
	while ('\0' != *format)
	{
		if ('%' == *format)
			len += convert(&format, &va, getfl(&va, &format)) - 1;
		else
			FT_PUTCHAR(*format);
		len++;
		format++;
	}
	va_end(va);
	return (len);
}
