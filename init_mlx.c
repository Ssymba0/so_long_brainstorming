/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:26 by isabri            #+#    #+#             */
/*   Updated: 2022/03/23 17:52:27 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *mlx, t_obj *img)
{
	int	width;
	int	height;

	mlx->mlx = mlx_init();
	img->cpath = "./img/coin.xpm";
	img->dpath = "./img/door.xpm";
	img->epath = "./img/door_exit.xpm";
	img->ppath = "./img/player.xpm";
	img->wpath = "./img/wall.xpm";
	img->c = mlx_xpm_file_to_image(mlx, img->cpath, &width, &height);
	img->d = mlx_xpm_file_to_image(mlx, img->dpath, &width, &height);
	img->e = mlx_xpm_file_to_image(mlx, img->epath, &width, &height);
	img->p = mlx_xpm_file_to_image(mlx, img->ppath, &width, &height);
	img->w = mlx_xpm_file_to_image(mlx, img->wpath, &width, &height);
}
