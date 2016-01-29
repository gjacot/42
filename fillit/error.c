/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:30:46 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/29 17:37:50 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	error()
{
	ft_putstr("error\n");
	exit(0);
}

void	error2(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(0);
}
