/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:32:28 by gjacot            #+#    #+#             */
/*   Updated: 2016/05/12 20:54:04 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_the_following(t_get *get, char **line, int ret, char **str)
{
	int		i;
	char	*str1;

	str1 = ft_strdup(*str);
	ft_strdel(str);
	i = 0;
	while (str1[i] != '\n' && str1[i] != '\0')
		i++;
	*line = ft_strsub(str1, 0, i);
	if (ret == 0 && ft_strlen(str1) == 0 && ft_strlen(get->tmp) == 0)
		return (0);
	ft_strdel(&get->tmp);
	get->tmp = ft_strsub(str1, i + 1, ft_strlen(str1));
	free(str1);
	return (1);
}

void	get_no_leak(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = ft_strjoin(*s1, *s2);
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_get	get;
	char			*str;
	int				ret;

	str = NULL;
	if (get.tmp == NULL)
		get.tmp = ft_strnew(BUFF_SIZE);
	if (fd <= 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (get.tmp != NULL)
	{
		str = ft_strdup(get.tmp);
		ft_strclr(get.tmp);
	}
	while ((ret = read(fd, get.tmp, BUFF_SIZE)) > 0)
	{
		get.tmp[ret] = '\0';
		get_no_leak(&str, &get.tmp);
		if (ft_strchr(get.tmp, '\n') != NULL)
			break ;
	}
	if (ret < 0)
		return (-1);
	return (get_the_following(&get, line, ret, &str));
}
