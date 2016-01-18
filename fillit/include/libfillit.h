/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:22:16 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 14:39:44 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFILLIT_H
# define	LIBFILLIT_H
#include <stdlib.h>

int		error(void);
int 	test(void);
int		lastcheck(char *buf, int i);
int		solveit(char *buf);

#endif
