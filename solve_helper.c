/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 23:39:51 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 21:35:55 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_tetris(char **board, int x, int y, t_tetris *tet)
{
	int a;
	int b;

	tet->flag = -1;
	board[x][y] = tet->ch;
	a = x - tet->pnt2[0];
	b = y - tet->pnt2[1];
	board[a][b] = tet->ch;
	a = x - tet->pnt3[0];
	b = y - tet->pnt3[1];
	board[a][b] = tet->ch;
	a = x - tet->pnt4[0];
	b = y - tet->pnt4[1];
	board[a][b] = tet->ch;
}

int		empty_space(char **board, int x, int y, t_tetris *t)
{
	int a;
	int b;

	if (board[x][y] != '.')
		return (-1);
	a = x - t->pnt2[0];
	b = y - t->pnt2[1];
	if (board[a] == NULL || board[a][b] == '\0')
		return (-1);
	if (a < 0 || b < 0 || board[a][b] != '.')
		return (-1);
	a = x - t->pnt3[0];
	b = y - t->pnt3[1];
	if (board[a] == NULL || board[a][b] == '\0')
		return (-1);
	if (a < 0 || b < 0 || board[a][b] != '.')
		return (-1);
	a = x - t->pnt4[0];
	b = y - t->pnt4[1];
	if (board[a] == NULL || board[a][b] == '\0')
		return (-1);
	if (a < 0 || b < 0 || board[a][b] != '.')
		return (-1);
	return (1);
}

int		empty_point(int x, int y, char **board)
{
	if (board[x][y] == '.')
		return (1);
	return (-1);
}

int		check(char **board, int x, int y, t_tetris *tet)
{
	if (empty_point(x, y, board) == (-1))
		return (-1);
	if (empty_space(board, x, y, tet) != 1)
		return (-1);
	return (1);
}

int		solve_board(char **map, t_tetris *tet, int n)
{
	int			x;
	int			y;
	t_tetris	*tmp;

	if (tet == NULL || tetris_left(tet) == (-1))
		return (1);
	tmp = tet;
	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			if (check(map, x, y, tmp) == 1)
			{
				insert_tetris(map, x, y, tmp);
				if (solve_board(map, tmp->next, n) == 1)
					return (1);
				map = reverse_board(map, tmp, n);
			}
			y++;
		}
		x++;
	}
	return (-1);
}
