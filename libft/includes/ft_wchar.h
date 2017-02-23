/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 12:53:50 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/13 12:58:04 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# define FT_PUTWCHAR(wch)	ft_putwchar_fd((wch), 1)
# define FT_PUTWSTR(wstr)	ft_putwstr_fd((wstr), 1)

# include <wchar.h>

size_t	ft_wstrlen(const wchar_t *wcs);
void	ft_putwchar(wchar_t wcs);
void	ft_putwchar_fd(wchar_t wcs, int fd);
void	ft_putwstr(const wchar_t *wcs);
void	ft_putwstr_fd(const wchar_t *wcs, int fd);
void	ft_wstrdel(wchar_t	**as);
wchar_t	*ft_wstrnew(size_t size);
wchar_t	*ft_wstrdup(const wchar_t *wcs);
wchar_t	*ft_wstrcpy(wchar_t *dest, const wchar_t *str);
int		ft_wbits(wchar_t wch);

#endif
