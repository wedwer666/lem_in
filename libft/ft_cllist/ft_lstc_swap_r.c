/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_swap_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:03:48 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/15 19:12:45 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"

void	ft_lstc_swap_r(t_c_list **root)
{
	void	*content;
	size_t	content_size;

	if (NULL == root || NULL == *root)
		return ;
	content = GET_CONT(*root);
	content_size = GET_CONT_SIZE(*root);
	GET_CONT(*root) = GET_CONT(RIGHT(*root));
	GET_CONT_SIZE(*root) = GET_CONT_SIZE(RIGHT(*root));
	GET_CONT(RIGHT(*root)) = content;
	GET_CONT_SIZE(RIGHT(*root)) = content_size;
}
