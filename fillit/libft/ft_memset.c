/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:16:01 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/03 14:40:48 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}
