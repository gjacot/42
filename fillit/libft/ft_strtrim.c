/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:18:53 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/11 17:46:55 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		is_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t		rm_debut(char const *s)
{
	size_t	i;

	i = 0;
	while (is_white(s[i]))
		i++;
	return (i);
}

static size_t		rm_fin(char const *s)
{
	size_t len;

	len = ft_strlen(s);
	len--;
	while (is_white(s[len]))
		len--;
	return (len);
}

char				*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;
	size_t	fin;
	size_t	debut;

	i = 0;
	debut = rm_debut(s);
	fin = rm_fin(s);
	if (debut == ft_strlen(s))
	{
		if (!(str = ft_memalloc((1))))
			return (NULL);
		return (str);
	}
	if (!(str = ft_memalloc(((fin - debut) + 2))))
		return (NULL);
	while (debut <= fin)
	{
		str[i] = s[debut];
		debut++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
