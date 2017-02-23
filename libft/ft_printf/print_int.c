/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:13:32 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/10 15:54:40 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*get_unbr(va_list *va, char ch, int mod_fl)
{
	uintmax_t	nbr;

	if (ft_strchr("BOUp", ch) || L_FL == mod_fl)
		nbr = va_arg(*va, t_ulong);
	else if (HH_FL == mod_fl)
		nbr = (t_uchar)va_arg(*va, t_uint);
	else if (H_FL == mod_fl)
		nbr = (t_ushort)va_arg(*va, t_uint);
	else if (LL_FL == mod_fl)
		nbr = va_arg(*va, t_ulonglong);
	else if (J_FL == mod_fl)
		nbr = va_arg(*va, uintmax_t);
	else if (Z_FL == mod_fl)
		nbr = va_arg(*va, size_t);
	else
		nbr = va_arg(*va, t_uint);
	if (ft_strchr("bB", ch))
		return (ft_utoab(nbr, BIN_BASE));
	else if (ft_strchr("oO", ch))
		return (ft_utoab(nbr, OCT_BASE));
	else if (ft_strchr("xp", ch))
		return (ft_utoab(nbr, HEX_BASE_S));
	else if ('X' == ch)
		return (ft_utoab(nbr, HEX_BASE_B));
	return (ft_utoa(nbr));
}

char	*get_nbr(va_list *va, char ch, int mod_fl)
{
	intmax_t	nbr;

	if (ft_strchr("bBoOuUxXp", ch))
		return (get_unbr(va, ch, mod_fl));
	else if ('D' == ch || L_FL == mod_fl)
		nbr = va_arg(*va, long int);
	else if (HH_FL == mod_fl)
		nbr = (char)va_arg(*va, int);
	else if (H_FL == mod_fl)
		nbr = (short)va_arg(*va, int);
	else if (LL_FL == mod_fl)
		nbr = va_arg(*va, long long int);
	else if (J_FL == mod_fl)
		nbr = va_arg(*va, intmax_t);
	else if (Z_FL == mod_fl)
		nbr = (va_arg(*va, intmax_t));
	else
		nbr = va_arg(*va, int);
	return (ft_itoa(nbr, 0));
}

char	*get_diez_or_plus(char **nbr, char ch, t_flag fl)
{
	char	*tmp;

	if ('p' == ch)
		return (ft_strdup("0x"));
	if (fl.diez)
	{
		if (ft_strchr("bB", ch))
			return (ft_strdup("B"));
		else if (ft_strchr("oO", ch) && '0' != **nbr)
			return (ft_strdup("0"));
		else if ('x' == ch && **nbr && '0' != **nbr)
			return (ft_strdup("0x"));
		else if ('X' == ch && **nbr && '0' != **nbr)
			return (ft_strdup("0X"));
	}
	if (fl.plus && ft_strchr("dDi", ch) && '-' != **nbr)
		return ((char*)ft_memset(ft_strnew(2), fl.plus, 1));
	if ('-' == **nbr)
	{
		tmp = *nbr;
		*nbr = ft_strdup(*nbr + 1);
		ft_strdel(&tmp);
		return (ft_strdup("-"));
	}
	return (ft_strdup(""));
}

int		put_prep_nbr(char **str1, char **str2, char **str3, char **str4)
{
	size_t	size;

	FT_PUTSTR(*str1);
	FT_PUTSTR(*str2);
	FT_PUTSTR(*str3);
	FT_PUTSTR(*str4);
	size = ft_strlen(*str1) + ft_strlen(*str2) +
			ft_strlen(*str3) + ft_strlen(*str4);
	ft_strdel(str1);
	ft_strdel(str2);
	ft_strdel(str3);
	ft_strdel(str4);
	return ((size_t)size);
}

int		print_int(va_list *va, char ch, t_flag fl)
{
	char	*nbr;
	char	*bs;
	char	*buff;
	int		size;
	char	*prec;

	nbr = get_nbr(va, ch, fl.mod_fl);
	nbr[0] = !(fl.prec - 1) && '0' == nbr[0] ? '\0' : nbr[0];
	bs = get_diez_or_plus(&nbr, ch, fl);
	size = (fl.prec - 1) - ft_strlen(nbr);
	size -= ft_strchr("oO", ch) ? ft_strlen(bs) : 0;
	size = size < 0 ? 0 : size;
	prec = (char*)ft_memset(ft_strnew(size), '0', size);
	size = fl.len - ft_strlen(nbr) - ft_strlen(bs) - ft_strlen(prec);
	size = size < 0 ? 0 : size;
	buff = (char*)ft_memset(ft_strnew(size), fl.minus || fl.prec
			? ' ' : fl.blank, size);
	if (fl.minus)
		return (put_prep_nbr(&bs, &prec, &nbr, &buff));
	else if ('0' == fl.blank)
		return (put_prep_nbr(&bs, &buff, &prec, &nbr));
	return (put_prep_nbr(&buff, &bs, &prec, &nbr));
}
