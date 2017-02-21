/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_funct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:07:05 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/06 15:28:36 by mmitriuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lem_in.h"
#include <string.h>

//analyze the first occurence of letter in string
char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)															
		return ((char*)(s + i));
	return (NULL);
}
//copy the duplicate 
char		*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(s1) + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_strcpy(new_str, s1));
}

//analyze if given numbers are with minus or plus
void		ft_putnbr(int nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return ;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
	return ;
}

//use the atoi function to check the conversion
int			ft_atoi_verify(char *str)
{
	while ((str[index] == '\t') || (str[index] == '\n') || (str[index] == ' ')
			|| (str[index] == '\f') || (str[index] == '\v') || str[index] == '\r')
		index++;
	if (str[index] == '-')
		ft_error();
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] && (str[index] >= '0') && (str[index] <= '9'))
	{
		if (!(str[i] >= '0') && (str[i] <= '9'))
			ft_error();
		nr *= 10;
		nr += (int)str[index] - '0';
		index++;
	}
	if (str[i] != 0)
		ft_error();
	if (n == 1)
		return (-nr);
	return (nr);
}

//connect two strings given as arguments
char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (*s1)
		str[++i] = *s1++;
	while (*s2)
		str[++i] = *s2++;
	str[++i] = '\0';
	return (str);
}
