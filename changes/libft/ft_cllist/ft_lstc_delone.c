/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:32:14 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/20 16:29:00 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_printf.h"

void	ft_lstc_delone(t_c_list **root, void (*del)(void*, size_t))
{
	if (NULL != root && NULL != *root)
		del(GET_CONT(*root), GET_CONT_SIZE(*root));
	ft_memdel((void**)root);
}
