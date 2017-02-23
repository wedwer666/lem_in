/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:30:21 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/25 14:55:24 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_wchar.h"

wchar_t		*ft_wstrnew(size_t size)
{
	return ((wchar_t*)ft_memalloc(sizeof(wchar_t) * (size + 1)));
}
