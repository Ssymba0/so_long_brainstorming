/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:23 by isabri            #+#    #+#             */
/*   Updated: 2022/03/23 17:52:24 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror("malloc error\n");
	map->map = 0;
	map->height = 1;
	map->width = 0;
	map->c_occ = 0;
	map->p_occ = 0;
	map->e_occ = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->moves = 0;
	return (map);
}

void	map_alloc(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		perror("malloc error\n");
}
