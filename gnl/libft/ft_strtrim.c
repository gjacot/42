/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:41:44 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/22 12:10:38 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(char *dst, int lastl, int start, char const *s)
{
	int i;

	i = 0;
	while (lastl != 0)
	{
		dst[i] = s[start];
		start++;
		i++;
		lastl--;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*dst;
	int		lastl;

	start = 0;
	lastl = 0;
	dst = NULL;
	end = ft_strlen(s);
	if (s != NULL)
	{
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
		lastl = end - start;
		if (end == 0)
			return ("");
		dst = (char *)ft_memalloc(lastl + 1);
		if (dst != NULL)
			return (trim(dst, lastl, start, s));
	}
	return (NULL);
}
