/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:28 by isabri            #+#    #+#             */
/*   Updated: 2022/03/24 13:23:28 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_this(t_data *data)
{
	mlx_destroy_image(data->mlx, data->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_obj	img;
	t_map	*map;
	t_data	data;

	map = init_map();
	get_map(map, ac, av[1]);
	if (!check_map(map))
	{
		printf("wrong map\n");
		exit(0);
	}
	init_mlx(&mlx, &img);
	mlx.win = mlx_new_window(mlx.mlx, map->width * IMG_W, \
	map->height * IMG_H, "so_long");
	draw_map(&img, mlx.mlx, mlx.win, map);
	data.mlx = mlx.mlx;
	data.win = mlx.win;
	data.map = map;
	data.img = &img;
	system("leaks so_long");
	mlx_key_hook(data.win, moves, &data);
	mlx_hook(mlx.win, 17, 0, quit_this, &data);
	mlx_loop(mlx.mlx);
}
