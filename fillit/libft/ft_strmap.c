/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:15:21 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/09 20:37:09 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	res = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (s && (*f))
	{
		while (s[i])
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
