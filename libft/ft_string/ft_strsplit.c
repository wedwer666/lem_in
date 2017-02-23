/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:34:45 by pcervac           #+#    #+#             */
/*   Updated: 2017/01/21 17:24:06 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

static size_t	get_nr_words(char const *s, char c)
{
	int	nr_words;
	int	i;

	nr_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nr_words++;
		i++;
	}
	return (nr_words);
}

static size_t	get_len_word(char const *s, size_t start, char c)
{
	int		count;

	count = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		count++;
		start++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	tab = NULL;
	if (s != NULL)
	{
		if (NULL != (tab = (char**)ft_memalloc(sizeof(char*) *
						(get_nr_words(s, c) + 1))))
		{
			i = 0;
			j = 0;
			while (s[i] != '\0')
			{
				if (s[i] != c && (i == 0 || (i != 0 && s[i - 1] == c)))
					tab[j++] = ft_strsub(s, i, get_len_word(s, i, c));
				i++;
			}
		}
	}
	return (tab);
}
