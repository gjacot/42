/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:15:46 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/09 20:38:54 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (s && (*f))
	{
		while (s[i])
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
