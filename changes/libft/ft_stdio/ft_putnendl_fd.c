/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:08:13 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 17:13:56 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdio.h"
#include "ft_string.h"

void	ft_putnendl_fd(const char *str, size_t start, size_t nr, int fd)
{
	if (fd > 0 && str != NULL)
	{
		if (start < ft_strlen(str) && start + nr < ft_strlen(str))
		{
			write(fd, &str[start], nr);
			ft_putchar_fd('\n', fd);
		}
	}
}
