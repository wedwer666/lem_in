/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:58:41 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/13 12:59:04 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# define FT_ISALPHA(ch)	(((ch)>='a' && (ch)<='z')||((ch)>='A' && ch<='Z'))
# define FT_ISASCII(ch)	((ch) >= 0 && (ch) <= 127)
# define FT_ISDIGIT(ch)	((ch) >= '0' && (ch) <= '9')
# define FT_ISPRINT(ch)	((ch) >= 32 && (ch) <= 126)
# define FT_TOUPPER(ch)	((ch) >= 'a' && (ch) <= 'z' ? (ch) - 32 : (ch))
# define FT_TOLOWER(ch)	((ch) >= 'A' && (ch) <= 'Z' ? (ch) - 32 : (ch))
# define FT_ISALNUM(ch)	FT_ISALPHA(ch) || FT_ISDIGIT(ch)

int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
int		ft_isspace(int ch);

int		ft_toupper(int ch);
int		ft_tolower(int ch);

#endif
