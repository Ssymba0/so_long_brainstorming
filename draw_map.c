/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:03 by isabri            #+#    #+#             */
/*   Updated: 2022/03/23 17:52:04 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_obj *img, void *mlx, void *win, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img->w, j * IMG_H, i * IMG_W);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img->c, j * IMG_H, i * IMG_W);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img->p, j * IMG_H, i * IMG_W);
			else if (map->map[i][j] == 'E' && map->c_occ != 0)
				mlx_put_image_to_window(mlx, win, img->d, j * IMG_H, i * IMG_W);
			else if (map->c_occ == 0 && map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img->e, j * IMG_H, i * IMG_W);
			j++;
		}
		i++;
	}
	printf("%d\n", map->moves);
}
