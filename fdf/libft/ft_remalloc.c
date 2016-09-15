/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:40:12 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/13 17:40:14 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_remalloc(char *s1, size_t size)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (s2 == NULL)
		return (NULL);
	i = -1;
	bzero(s2, size + 1);
	if (s1 != NULL)
	{
		while (s1[++i])
			s2[i] = s1[i];
		s2[i] = '\0';
		free(s1);
	}
	return (s2);
}
