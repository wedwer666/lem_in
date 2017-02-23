/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:51:02 by pcervac           #+#    #+#             */
/*   Updated: 2017/02/16 20:55:31 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_ctype.h"

void	ft_strtolower(char *str)
{
	if (NULL == str)
		return ;
	while ('\0' != *str)
	{
		*str = ft_tolower(*str);
		str++;
	}	
}
