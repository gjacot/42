/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 06:41:33 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/08 02:55:16 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;
	size_t j;
	size_t len;

	i = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while ((s1[i] != '\0') && (i < n))
	{
		k = i;
		j = 0;
		while ((s1[k] == s2[j]) && (k < n))
		{
			j++;
			k++;
			if (j == len)
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
