/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:16:06 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/25 14:19:48 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_wchar.h"

void	ft_wstrdel(wchar_t **as)
{
	ft_memdel((void**)as);
}
