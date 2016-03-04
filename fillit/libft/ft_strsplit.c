/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:16:28 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/18 00:32:50 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t		lettre;
	size_t		index;

	lettre = 0;
	index = 0;
	while (s[lettre])
	{
		while (s[lettre] == c)
			lettre++;
		if (s[lettre] != c && s[lettre])
		{
			index++;
			lettre++;
			while (s[lettre] != c && s[lettre])
				lettre++;
		}
	}
	return (index);
}

static char		*add_word(size_t *lettre, char const *s, char c)
{
	size_t		size;
	size_t		index;
	char		*word;

	size = *lettre;
	index = 0;
	while (s[size] && s[size] != c)
		size++;
	word = ft_strnew((size - *lettre) + 1);
	if (word)
	{
		word[size - *lettre] = '\0';
		while (*lettre < size)
		{
			word[index] = s[*lettre];
			index++;
			*lettre += 1;
		}
		return (word);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		lettre;
	size_t		index;

	lettre = 0;
	index = 0;
	tab = NULL;
	if (s)
		tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (tab)
	{
		while (index < count_word(s, c))
		{
			while (s[lettre] == c)
				lettre++;
			if (s[lettre] != c && s[lettre])
				tab[index++] = add_word(&lettre, s, c);
		}
		tab[index] = NULL;
		return (tab);
	}
	return (0);
}
