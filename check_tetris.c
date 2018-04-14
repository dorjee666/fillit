/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:51:02 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 20:20:11 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_link(char str[], int x, int y)
{
	int	count;

	count = 0;
	if (str[4 * x + y] == '#')
	{
		if ((x - 1) >= 0 && str[(4 * (x - 1)) + y] == '#')
			count++;
		if ((x + 1) < 4 && str[(4 * (x + 1)) + y] == '#')
			count++;
		if ((y - 1) >= 0 && str[4 * x + (y - 1)] == '#')
			count++;
		if ((y + 1) < 4 && str[4 * x + (y + 1)] == '#')
			count++;
	}
	return (count);
}

int		final_valid1(char str[])
{
	int x;
	int y;
	int count;

	x = 0;
	count = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			count = count + count_link(str, x, y);
			y++;
		}
		x++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (-1);
}

int		final_valid(char *str)
{
	char	arr[17];
	int		i;

	arr[16] = '\0';
	i = 0;
	while (*str)
	{
		i = 0;
		while (i < 16)
		{
			arr[i] = *str;
			str++;
			i++;
		}
		if (final_valid1(arr) != 1)
			return (-1);
	}
	return (1);
}
