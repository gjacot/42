/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:22:16 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 16:27:12 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFILLIT_H
# define	LIBFILLIT_H
#include <stdlib.h>

int		error(void);
int		error2(char *str);
int 	test(void);
int		lastcheck(char *buf, int i);
int		solveit(char *buf);
char 	**inittab(char *buf);
char	**remplir_tab(char *buf);
void	affiche(char **tab_piece);
int 	compte_tab(char *buf);

#endif
