/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:58:39 by gjacot            #+#    #+#             */
/*   Updated: 2016/09/15 16:05:50 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*lst_init(t_env *e)
{
	e->line_i = 0;
	e->y_max = 1000;
	e->mlx->x = 0;
	e->mlx->y = 0;
	e->mlx->color = 0x00700FF;
	e->mlx->mlx = mlx_init();
	mlx_init();
	e->mlx->win = mlx_new_window(e->mlx->mlx, 1500, e->y_max, "fdf");
	e->mlx->img = mlx_new_image(e->mlx->mlx, 1500, e->y_max);
	e->mlx->data = (int *)mlx_get_data_addr(e->mlx->win, &e->mlx->bit, &e->line,
	&e->mlx->end);
	e->line = e->line / 4;
	return (e->mlx);
}

int		set_line_number(t_env *e)
{
	int i;
	int ret;

	i = 0;
	while ((ret = get_next_line(e->fd, &e->getline)) > 0)
		i++;
	if (ret < 0)
	{
		ft_putstr("error: unable to read file\n");
		exit(0);
	}
	i--;
	ft_putnbr(i);
	ft_putchar('\n');
	return (i);
}

t_point		*find_sumit(t_env *e, int *i)
{
	int		nb;
	int		nb2;

	while (e->getline[*i] == ' ' || e->getline[*i] == '\t')
		(*i)++;
	nb = ft_atoi(&e->getline[*i]);
	nb2 = nb;
	while (nb2 > 9)
	{
		nb2 = nb2 / 10;
		(*i)++;
	}
	e->point = fill_lst(nb, e);
	(*i)++;
	e->point = e->point->prev;
	e->point->next = NULL;
	return (e->point);
}

t_point		**get_line(t_env *e)
{
	int i;

	while (get_next_line(e->fd, &e->getline) > 0)
	{
		i = 0;
		while (i < (int)ft_strlen(e->getline))
		{
			e->point = find_sumit(e, &i);
			if (e->point->prev == NULL)
			{
				e->lines[e->line_i] = e->point;
				(e->line_i)++;
			}
			else if(e->point->prev->y != e->point->y)
			{
				e->lines[e->line_i] = e->point;
				(e->line_i)++;
			}
		}
		if (e->point->prev)
			e->point->y = e->point->prev->y + 50;
	}
	return (e->lines);
}

void	ft_test(t_env *e)
{
	e->point = e->point->first;
	while (e->point->next)
	{
		printf("%d  ", e->point->z);
		e->point = e->point->next;
	}
}

int			main(int argc, char **argv)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	e->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	e->point = (t_point *)malloc(sizeof(t_point));
	e->getline = (char *)malloc(sizeof(char));
	e->fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	e->lines = (t_point **)malloc((sizeof(t_point *) * set_line_number(e)));
	e->mlx = lst_init(e);
	e->fd = open(argv[1], O_RDONLY);
	e->lines = get_line(e);
	ft_test(e);
	return (0);
}
