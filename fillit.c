/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 21:41:10 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 21:26:31 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(int fd)
{
	char		**map;
	char		*input;
	t_tetris	*tetriminos;

	tetriminos = NULL;
	if ((input = read_file(fd)) == NULL)
		return (-1);
	if ((input = valid_input(input)) == NULL)
		return (-1);
	if ((tetriminos = get_tetris(tetriminos, input)) == NULL)
		return (-1);
	if ((map = solve_square(tetriminos)) == NULL)
		return (-1);
	print_map(map);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;

	str = "usage: input_file\n   input_file: file with valid tetriminos\n";
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (solve(fd) == (-1))
			write(1, "error\n", 6);
		return (0);
	}
	else
		write(1, str, ft_strlen(str));
	return (0);
}
