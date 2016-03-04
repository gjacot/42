/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:17:53 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/03 14:43:27 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	iend;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	iend = i;
	while (src[i - iend] != '\0' && i < size - 1)
	{
		dst[i] = src[i - iend];
		i++;
	}
	if (iend < size)
		dst[i] = '\0';
	return (iend + ft_strlen(src));
}
