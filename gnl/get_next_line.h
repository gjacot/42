/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:44:15 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/31 18:21:37 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 3

int		get_next_line(const int fd, char **line);
int		get_next_next_line(int *i, char *tmp);

#endif










