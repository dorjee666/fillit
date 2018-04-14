/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:36:19 by dphuntso          #+#    #+#             */
/*   Updated: 2018/03/25 20:30:16 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_memcopy(char *old, char *new, int len)
{
	while (len--)
	{
		*new = *old;
		new++;
		old++;
	}
}

char	*resize_mem(char *old, int oldlen, int newlen)
{
	char *str;

	if ((str = malloc(newlen)) == NULL)
		return (NULL);
	ft_memcopy(old, str, oldlen);
	free(old);
	return (str);
}

char	*read_file(int fd)
{
	int		ret;
	char	*buff;
	int		buff_len;
	size_t	buff_capacity;

	buff_capacity = 549;
	buff_len = 0;
	if ((buff = malloc(buff_capacity)) == NULL)
		return (0);
	while ((ret = read(fd, buff + buff_len, buff_capacity - buff_len)) > 0)
	{
		buff_len += ret;
		if ((int)buff_capacity == buff_len)
		{
			buff = resize_mem(buff, buff_capacity, buff_capacity + 549);
			buff_capacity += 549;
		}
	}
	if (buff_len > 545 || buff_len == 0)
		return (NULL);
	buff[buff_len] = '\0';
	return (buff);
}
