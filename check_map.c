/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:58 by isabri            #+#    #+#             */
/*   Updated: 2022/03/23 17:51:59 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_shape(t_map *map)
{
	int	width;
	int	i;

	width = map->width;
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_top_bot(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while ((i == 0 || i == map->height - 1) && map->map[i][j])
		{
			if (map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (i < map->height)
		return (0);
	return (1);
}

int	check_borders(t_map	*map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i])
	{
		j = ft_strlen(map->map[i]) - 1;
		if (map->map[i][0] != '1' || map->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_content(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != 'E' && map->map[i][j] != 'C' \
			&& map->map[i][j] != '1' \
			&& map->map[i][j] != '0' && map->map[i][j] != 'P' && \
			(map->e_occ == 0 || map->p_occ != 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (!check_shape(map) || !check_top_bot(map) || \
	!check_borders(map) || !check_content(map))
		return (0);
	return (1);
}
