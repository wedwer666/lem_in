/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:22:02 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/20 12:50:18 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>

# define GET_INT(val)	(*(int*)(val))

int			ft_abs(int nbr);
int			ft_atoi(const char *nb_ptr);
long		ft_atol(const char *nb_ptr);
long long	ft_atoll(const char *nb_ptr);
int			ft_atoib(const char *str, const char *base);
long		ft_atolb(const char *str, const char *base);
long long	ft_atollb(const char *str, const char *base);
char		*ft_atoibb(const char *str, const char *fbase, const char *tbase);
char		*ft_atolbb(const char *str, const char *fbase, const char *tbase);
char		*ft_atollbb(const char *str, const char *fbase, const char *tbase);
char		*ft_itoa(intmax_t value, int sign);
char		*ft_itoab(intmax_t value, const char *base, int sign);
char		*ft_utoa(uintmax_t value);
char		*ft_utoab(uintmax_t value, const char *base);
char		*ft_ftoa(long double f, size_t prec, int conv);

void		*ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		ft_memdel(void **dest);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

#endif
