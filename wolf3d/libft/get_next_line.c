/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:54:41 by gjacot            #+#    #+#             */
/*   Updated: 2016/08/24 18:54:47 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *buf, int ret)
{
	int diff;

	if (ret == 0)
		ft_bzero(buf, BUFF_SIZE + 1);
	else if (ft_strchr(buf, '\n'))
	{
		diff = ft_strchr(buf, '\n') - buf + 1;
		buf = ft_strncpy(buf, &buf[diff], BUFF_SIZE + 1);
	}
	else
		ft_bzero(buf, BUFF_SIZE + 1);
	return (buf);
}

int		ft_read_line(char *buf, char **line, int fd, int len)
{
	int nb_char;

	nb_char = 0;
	if (!ft_strchr(buf, '\n'))
		nb_char = ft_strlen(buf);
	while (!ft_strchr(buf, '\n'))
	{
		*line = ft_remalloc(*line, nb_char + len + 1);
		nb_char += len;
		if (!(*line))
			return (-1);
		ft_strncat(*line, buf, nb_char);
		ft_bzero(buf, BUFF_SIZE + 1);
		len = read(fd, buf, BUFF_SIZE);
		if (len <= 0 && nb_char == 0)
			return (len);
		else if (len == 0 && nb_char > 0)
			return (1);
	}
	nb_char += ft_strchr(buf, '\n') - buf + 1;
	*line = ft_remalloc(*line, nb_char);
	if (!(*line))
		return (-1);
	ft_strlcat(*line, buf, nb_char);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf;
	int			ret;

	if (line == NULL)
		return (-1);
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (!buf)
		return (-1);
	*line = NULL;
	ret = ft_read_line(buf, line, fd, 0);
	if (ret == -1)
		return (-1);
	buf = ft_save(buf, ret);
	return (ret);
}
