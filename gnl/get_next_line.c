/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:44:58 by gjacot            #+#    #+#             */
/*   Updated: 2016/04/06 18:58:48 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_the_following(t_get *get, char *str, char **line, int ret)
{
	int	i;

	i = 1;
	while (str[i - 1] != '\n' && str[i - 1] != '\0')
		i++;
			ft_putstr("ok\n");
	if (i <= (int)ft_strlen(str))
	{
		get->tmp = ft_strsub(str, i, ft_strlen(str));
		*line = ft_strsub(str, 0, i - 1);
		printf("tmp=%s\nstr=%s", get->tmp, str);
		free(str);
		str = NULL;
	}
	if (ret < BUFF_SIZE)
		return (0);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_get	get;
	int				ret;
	char			*str;

	str = NULL;
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (!get.tmp)
		get.tmp = ft_strnew(BUFF_SIZE);
	else
	{
		printf("tmp before =%s\n", get.tmp);
		str = ft_strsub(get.tmp, 0, ft_strlen(get.tmp));
		//ft_strclr(get.tmp);
	}
	while (ft_strchr(get.tmp, '\n') == NULL && ret != 0)
	{
		ret = read(fd, get.tmp, BUFF_SIZE);
		if (str == NULL)
			str = ft_strsub(get.tmp, 0, ft_strlen(get.tmp));
		else
			str = ft_strjoin(str, get.tmp);
	}
	return (get_the_following(&get, str, line, ret));
}
