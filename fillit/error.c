/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:30:46 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 15:45:39 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	error2(char *str)
{
	ft_putstr(str);
	exit(0);
}
