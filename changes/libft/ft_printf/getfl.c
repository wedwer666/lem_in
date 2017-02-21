/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:06:35 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/08 17:48:02 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static const t_flag		g_nullflag = {0, 0, 0, 0, 0, 0, 0, ' ', 0, 0};
static const char		*g_mgflags = "0#-+ $\'";

static void	get_mgflags(const char **format, t_flag *fl)
{
	while (1)
	{
		if (**format == '0')
			fl->blank = **format;
		else if (**format == '#')
			fl->diez = 1;
		else if (**format == '-')
			fl->minus = 1;
		else if (**format == '+' || **format == ' ')
			fl->plus = !fl->plus || ' ' == fl->plus ? **format : fl->plus;
		else if (**format == '$')
			fl->dollar = 1;
		else if (**format == '\'')
			fl->quote = 1;
		else
			break ;
		(*format)++;
	}
}

static void	get_precflag(va_list *va, const char **format, t_flag *fl)
{
	int		prec;

	fl->prec = 0;
	(*format)++;
	prec = 0;
	if (**format == '*')
	{
		prec = va_arg(*va, int);
		prec = prec < 0 ? -1 : prec;
		(*format)++;
	}
	else
		while (FT_ISDIGIT(**format))
		{
			prec = prec * 10 + (**format - '0');
			(*format)++;
		}
	if (fl->prec < ++prec)
		fl->prec = prec;
}

static void	get_lenflag(va_list *va, const char **format, t_flag *fl)
{
	fl->len = 0;
	if (**format == '*')
	{
		fl->len = va_arg(*va, int);
		fl->minus = fl->len < 0 ? 1 : 0;
		fl->len = ft_abs(fl->len);
		(*format)++;
	}
	else
		while (FT_ISDIGIT(**format))
		{
			fl->len = fl->len * 10 + (**format - '0');
			(*format)++;
		}
}

static void	get_sizeflags(const char **format, t_flag *fl)
{
	int		tmp;

	tmp = 0;
	while (ft_strchr("hljzL", **format) && **format)
	{
		if ('L' == **format)
			fl->bl_fl = BL_FL;
		if ('h' == **format && **format == *(*format + 1))
			tmp = HH_FL;
		else if ('h' == **format)
			tmp = H_FL;
		else if ('l' == **format)
			tmp = L_FL;
		else if ('l' == **format && **format == *(*format + 1))
			tmp = LL_FL;
		else if ('j')
			tmp = J_FL;
		else
			tmp = Z_FL;
		fl->mod_fl = tmp > fl->mod_fl ? tmp : fl->mod_fl;
		*format += ((HH_FL == tmp) || (LL_FL == tmp) ? 2 : 1);
	}
}

t_flag		getfl(va_list *va, const char **format)
{
	t_flag	tmp;

	tmp = g_nullflag;
	(*format)++;
	while (1)
	{
		if (ft_strchr(g_mgflags, **format) && **format)
			get_mgflags(format, &tmp);
		else if (FT_ISDIGIT(**format) || **format == '*')
			get_lenflag(va, format, &tmp);
		else if ('.' == **format)
			get_precflag(va, format, &tmp);
		else if (ft_strchr("hljzL", **format) && **format)
			get_sizeflags(format, &tmp);
		else
			break ;
	}
	return (tmp);
}
