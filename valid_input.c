/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:20:59 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 20:23:50 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*remove_newline(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i != 0 && (i + 1) % 21 == 0)
		{
			if (str[i] != '\n')
				return (NULL);
			i++;
		}
		else
		{
			str[j] = str[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

char	*remove_newline2(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i != 0 && (i + 1) % 5 == 0)
		{
			if (str[i] != '\n')
				return (NULL);
			i++;
		}
		else
		{
			str[j] = str[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

int		valid_data(char *str)
{
	char	arr[17];
	int		i;
	int		count;

	arr[16] = '\0';
	i = 0;
	while (*str)
	{
		count = 0;
		i = 0;
		while (i < 16)
		{
			arr[i] = *str;
			if (arr[i] != '.' && arr[i] != '#')
				return (-1);
			if (arr[i] == '#')
				count++;
			i++;
			str++;
		}
		if (count != 4)
			return (-1);
	}
	return (1);
}

char	*valid_input(char *str)
{
	if ((ft_strlen(str) + 1) % 21 != 0)
		return (NULL);
	if ((str = remove_newline(str)) == NULL)
		return (NULL);
	if ((str = remove_newline2(str)) == NULL)
		return (NULL);
	if (valid_data(str) != 1)
		return (NULL);
	if (final_valid(str) != 1)
		return (NULL);
	return (str);
}
