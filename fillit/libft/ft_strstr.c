/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 06:16:37 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/17 23:56:13 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t k;
	size_t j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		k = i;
		j = 0;
		while (s1[k] == s2[j])
		{
			j++;
			k++;
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
