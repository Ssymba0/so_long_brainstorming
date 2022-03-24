/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:11 by isabri            #+#    #+#             */
/*   Updated: 2022/03/24 21:51:08 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_map *map, int ac, char *av)
{
	int		fd;
	int		i;

	fd = get_fd(ac, av);
	read_map_coord(fd, map);
	map_alloc(map);
	close(fd);
	fd = get_fd(ac, av);
	i = 0;
	while (i <= map->height)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	if (i == 0)
	{
		printf("error\n");
		exit(0);
	}
	get_player(map);
	get_coins(map);
	get_exit(map);
}

void	get_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p_occ += 1;
				map->p_x = j;
				map->p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_coins(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->c_occ += 1;
			j++;
		}
		i++;
	}
}

void	get_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				map->e_occ += 1;
			j++;
		}
		i++;
	}
}
