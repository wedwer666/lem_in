/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:54:12 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/25 16:56:23 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cllist.h"
#include "ft_stdlib.h"

t_c_list	*ft_lstc_new(void const *content, size_t content_size)
{
	t_c_list	*temp;

	if (NULL == (temp = (t_c_list*)ft_memalloc(sizeof(t_c_list))))
		return (NULL);
	if (NULL == (temp->content = ft_memalloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->right = NULL;
	temp->left = NULL;
	return (temp);
}
