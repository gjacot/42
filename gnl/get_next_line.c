/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:41:27 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/30 17:49:16 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_next_line(char **line, int i, char *tmp)
{
	*line = ft_strsub(tmp, 0, i);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	static char	*tmp;

	i = 0;
	ret = 0;
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
		tmp = ft_strnew(BUFF_SIZE);
		ret = read(fd, tmp, BUFF_SIZE);
		tmp[ret] = '\0';
		while (tmp[i] != '\n' && tmp[i] != '\0')
			i++;
		if (tmp[i] != '\n')
		{
			ft_putstr("okvsf\n");
			*line = ft_strjoin(*line, tmp);
			ft_putstr("ok\n");
			get_next_line(fd, line);
		}
	return (0);
}
