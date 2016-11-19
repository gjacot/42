/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:11:35 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/17 15:40:24 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	words_nb(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	nb = words_nb(s, c);
	tab = (char**)malloc(sizeof(char*) * nb + 1);
	if (!tab)
		return (NULL);
	while (i < nb && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		tab[i] = ft_strsub(&s[j], 0, word_len(&s[j], c));
		j = j + word_len(&s[j], c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
