/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:48:49 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 20:37:48 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*malloc_tetris(t_tetris *t, int size)
{
	char		ch;
	t_tetris	*tmp;

	ch = 'A';
	t = malloc(sizeof(t_tetris));
	tmp = t;
	t->ch = ch;
	t->flag = 0;
	t = guard_int(t);
	t->next = NULL;
	size--;
	while (size > 0)
	{
		t->next = malloc(sizeof(t_tetris));
		t = t->next;
		t->flag = 0;
		t->ch = ++ch;
		t = guard_int(t);
		t->next = NULL;
		size--;
	}
	return (tmp);
}

t_tetris	*get_a_tetris(t_tetris *tet)
{
	while (tet != NULL)
	{
		if (tet->flag == 0)
		{
			tet->flag = 1;
			return (tet);
		}
		tet = tet->next;
	}
	return (NULL);
}

t_tetris	*build_tetriminos(char str[], t_tetris *t)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			pos = 4 * i + j;
			if (str[pos] == '#' && t->pnt1[0] == (-1))
				rel_pos(t, t->pnt1, i, j);
			else if (str[pos] == '#' && t->pnt2[0] == 0 && t->pnt2[1] == 0)
				rel_pos(t, t->pnt2, i, j);
			else if (str[pos] == '#' && t->pnt3[0] == 0 && t->pnt3[1] == 0)
				rel_pos(t, t->pnt3, i, j);
			else if (str[pos] == '#' && t->pnt4[0] == 0 && t->pnt4[1] == 0)
				rel_pos(t, t->pnt4, i, j);
			j++;
		}
		i++;
	}
	return (t);
}

t_tetris	*get_tetriminos(t_tetris *tet, char *str)
{
	int			i;
	int			k;
	char		str2[17];
	t_tetris	*t;

	i = 0;
	str2[16] = '\0';
	while (str[i])
	{
		t = get_a_tetris(tet);
		k = 0;
		while (k < 16)
		{
			str2[k] = str[i];
			i++;
			k++;
		}
		t = build_tetriminos(str2, t);
	}
	return (tet);
}

t_tetris	*get_tetris(t_tetris *tet, char *str)
{
	int			size;

	size = (int)ft_strlen(str) / 16;
	if ((tet = malloc_tetris(tet, size)) == NULL)
	{
		write(1, "get_tetris.c line 112 failed\n", 29);
		return (NULL);
	}
	if ((tet = get_tetriminos(tet, str)) == NULL)
	{
		write(1, "get_tetris.c line 117 failed\n", 29);
		return (NULL);
	}
	return (tet);
}
