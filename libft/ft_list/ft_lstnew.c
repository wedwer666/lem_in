/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:24:00 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/22 19:16:10 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdlib.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if (NULL != (temp = (t_list*)ft_memalloc(sizeof(t_list))))
	{
		if (NULL != (temp->content = ft_memalloc(content_size)))
		{
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
			temp->next = NULL;
		}
	}
	return (temp);
}
