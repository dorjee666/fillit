/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:27:59 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 21:26:41 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (!(map[i] == NULL))
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1);
		i++;
	}
}

char	**malloc_board(char **map, int size)
{
	int i;

	i = 0;
	map = malloc(size * sizeof(char *) + 1);
	while (i < size)
	{
		map[i] = malloc(size * sizeof(char) + 1);
		map[i++][size] = '\0';
	}
	map[i] = NULL;
	return (map);
}

char	*map_to_str(char **map, int size)
{
	int		x;
	int		y;
	int		newl;
	char	*str;

	newl = 0;
	str = malloc(size * size * sizeof(char) + size);
	str[size * size] = '\0';
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			str[x * size + y + newl] = map[x][y];
			y++;
			if (y == size)
			{
				str[x * size + y + newl] = '\n';
				newl++;
			}
		}
		x++;
	}
	return (str);
}

char	**solve_square(t_tetris *tet)
{
	int			size;
	char		**map;
	t_tetris	*tmp;

	map = NULL;
	size = board_size(tet);
	map = malloc_board(map, size);
	clear_board(map, size);
	tmp = tet;
	while (solve_board(map, tmp, size) != 1)
	{
		if (size > 14)
			return (NULL);
		size++;
		if (!(map == NULL))
			free(map);
		map = malloc_board(map, size);
		clear_board(map, size);
	}
	return (map);
}
