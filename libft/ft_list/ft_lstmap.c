/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:24:48 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 17:49:25 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*temp;

	first = NULL;
	while (lst != NULL)
	{
		if (first == NULL)
		{
			first = f(lst);
			if (first == NULL)
				return (NULL);
			temp = first;
		}
		else
		{
			temp->next = f(lst);
			if (temp->next == NULL)
				return (NULL);
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (first);
}
