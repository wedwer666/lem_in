/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:34:15 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/25 14:45:48 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_wchar.h"

wchar_t	*ft_wstrdup(const wchar_t *s)
{
	wchar_t	*copy;

	copy = NULL;
	if (*s == L'\0')
		return (ft_wstrnew(sizeof(wchar_t)));
	else if (NULL != (copy = ft_wstrnew(ft_wstrlen(s))))
		ft_wstrcpy(copy, s);
	return (copy);
}
