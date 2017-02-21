/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:36:32 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/11 20:29:24 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <unistd.h>

# include "libft.h"

# define BIN_BASE	"01"
# define OCT_BASE	"01234567"
# define DEC_BASE	"0123456789"
# define HEX_BASE_S	"0123456789abcdef"
# define HEX_BASE_B	"0123456789ABCDEF"
# define BL_FL		1
# define HH_FL		1
# define H_FL		2
# define L_FL		3
# define LL_FL		4
# define J_FL		5
# define Z_FL		6

# define FT_PUTCHAR(ch)	ft_putchar(ch)
# define FT_PUTSTR(ch)	ft_putstr(ch)

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ulonglong;

typedef struct	s_flag
{
	int			diez;
	int			minus;
	int			plus;
	int			dollar;
	int			quote;
	int			len;
	int			prec;
	char		blank;
	int			mod_fl;
	int			bl_fl;
}				t_flag;

int				ft_printf(const char *format, ...);
t_flag			getfl(va_list *va, const char **format);
int				convert(const char **format, va_list *va, t_flag fl);

int				print_int(va_list *va, char ch, t_flag fl);
int				print_float(va_list *va, char ch, t_flag fl);
int				print_wstr(va_list *va, char ch, t_flag fl);
int				print_str(va_list *va, char ch, t_flag fl);
int				print_other(char ch, t_flag fl);
int				print_char(va_list *va, t_flag fl);
int				print_wchar(va_list *va, t_flag fl);

#endif
