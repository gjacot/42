/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:05:41 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/13 15:04:13 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (n > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}