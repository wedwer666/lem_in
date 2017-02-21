/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_swap_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:25:08 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/20 15:07:05 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

void	ft_lstc_swap_l(t_c_list **root)
{
	void	*content;
	size_t	content_size;

	if (NULL == root || *root == NULL)
		return ;
	content = GET_CONT(*root);
	content_size = GET_CONT_SIZE(*root);
	GET_CONT(*root) = GET_CONT(LEFT(*root));
	GET_CONT_SIZE(*root) = GET_CONT_SIZE(LEFT(*root));
	GET_CONT(LEFT(*root)) = content;
	GET_CONT_SIZE(LEFT(*root)) = content_size;
}
