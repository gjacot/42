/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:44:15 by gjacot            #+#    #+#             */
/*   Updated: 2016/04/06 14:20:34 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#include <stdio.h>

# define BUFF_SIZE 3

typedef	struct	s_get
{
	//struct s_list	next;
	char			*tmp;
	int				fd;
}				t_get;

int		get_next_line(const int fd, char **line);
int		get_next_next_line(char *tmp);

#endif
