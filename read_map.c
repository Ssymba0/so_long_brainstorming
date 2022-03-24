/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:38 by isabri            #+#    #+#             */
/*   Updated: 2022/03/23 17:52:39 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_coord(int fd, t_map *map)
{
	char	c;
	int		column_len;

	column_len = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (map->width < column_len)
			map->width = column_len;
		if (c == '\n')
		{
			map->height++;
			column_len = 0;
		}
		else
			column_len++;
	}
}
