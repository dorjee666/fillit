/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:34:25 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/23 23:10:27 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**reverse_board(char **old, t_tetris *tet, int n)
{
	int x;
	int y;

	x = 0;
	tet->flag = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			if (old[x][y] == tet->ch)
				old[x][y] = '.';
			y++;
		}
		x++;
	}
	return (old);
}

void	clear_board(char **board, int n)
{
	int x;
	int y;

	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			board[x][y] = '.';
			y++;
		}
		x++;
	}
}

int		four(char ch1, char ch2, char ch3, char ch4)
{
	if (ch1 == '#' || ch2 == '#')
		return (1);
	if (ch3 == '#' || ch4 == '#')
		return (1);
	return (-1);
}

int		board_size(t_tetris *tet)
{
	int			size;
	int			count;
	t_tetris	*temp;

	size = 0;
	count = 0;
	temp = tet;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	count = count * 4;
	while (size * size < count)
		size++;
	return (size);
}
