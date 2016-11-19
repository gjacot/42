/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:02:15 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/13 15:07:02 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int lens;

	lens = ft_strlen(s);
	while (lens != 0 && s[lens] != c)
		lens--;
	if (s[lens] == c)
		return ((char *)&s[lens]);
	return (NULL);
}
