/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:10:48 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/09 12:48:43 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t lendst;
	size_t lensrc;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	while (src[j] != '\0' && lendst < size - 1)
	{
		dst[lendst] = src[j];
		lendst++;
		j++;
	}
	dst[lendst] = '\0';
	return (lensrc + i);
}
