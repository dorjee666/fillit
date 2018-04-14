/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:50:41 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 15:25:03 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void		rel_pos(t_tetris *t, int pnt[2], int x, int y)
{
	if (t->pnt1[0] == (-1))
	{
		t->pnt1[0] = x;
		t->pnt1[1] = y;
	}
	else
	{
		pnt[0] = t->pnt1[0] - x;
		pnt[1] = t->pnt1[1] - y;
	}
}

int			hash(char ch)
{
	if (ch == '#')
		return (1);
	return (-1);
}

int			tetris_left(t_tetris *tet)
{
	t_tetris *temp;

	temp = tet;
	while (temp != NULL)
	{
		if (temp->flag == 1)
			return (1);
		temp = temp->next;
	}
	return (-1);
}

t_tetris	*guard_int(t_tetris *t)
{
	t->pnt1[0] = -1;
	t->pnt1[1] = 0;
	t->pnt2[0] = 0;
	t->pnt2[1] = 0;
	t->pnt3[0] = 0;
	t->pnt3[1] = 0;
	t->pnt4[0] = 0;
	t->pnt4[1] = 0;
	return (t);
}
