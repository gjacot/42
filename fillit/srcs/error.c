/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:30:46 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/04 18:44:52 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	error2(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(0);
}
