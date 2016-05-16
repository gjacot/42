/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:01:20 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/17 16:07:40 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	check;

	check = ft_strlen(s2);
	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j])
		{
			if (i + j >= n)
				return (NULL);
			if (j == check - 1)
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
