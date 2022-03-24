/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:34 by isabri            #+#    #+#             */
/*   Updated: 2022/03/24 12:11:23 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	if (data->map->map[y - 1][x] != '1' || (data->map->map[y - 1][x] == 'E' && \
	data->map->c_occ == 0))
	{
		data->map->moves++;
		if (data->map->map[y - 1][x] == 'C')
			data->map->c_occ--;
		if (data->map->map[y - 1][x] == 'E' && data->map->c_occ == 0)
			destroy_window(data);
		else if (data->map->map[y - 1][x] != 'E')
		{		
			data->map->p_y = y - 1;
			data->map->map[y][x] = '0';
			data->map->map[y - 1][x] = 'P';
			mlx_clear_window(data->mlx, data->win);
		}
	}
}

void	move_down(t_data *data)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	if (data->map->map[y + 1][x] != '1' || (data->map->map[y + 1][x] == 'E' && \
	data->map->c_occ == 0))
	{
		data->map->moves++;
		if (data->map->map[y + 1][x] == 'C')
			data->map->c_occ--;
		if (data->map->map[y + 1][x] == 'E' && data->map->c_occ == 0)
			destroy_window(data);
		else if (data->map->map[y + 1][x] != 'E')
		{	
			data->map->p_y = y + 1;
			data->map->map[y][x] = '0';
			data->map->map[y + 1][x] = 'P';
			mlx_clear_window(data->mlx, data->win);
		}
	}
}

void	move_left(t_data *data)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	if (data->map->map[y][x - 1] != '1' || (data->map->map[y][x - 1] == 'E' && \
	data->map->c_occ == 0))
	{
		data->map->moves++;
		if (data->map->map[y][x - 1] == 'C')
			data->map->c_occ--;
		if (data->map->map[y][x - 1] == 'E' && data->map->c_occ == 0)
			destroy_window(data);
		else if (data->map->map[y][x - 1] != 'E')
		{
			data->map->p_x = x - 1;
			data->map->map[y][x] = '0';
			data->map->map[y][x - 1] = 'P';
			mlx_clear_window(data->mlx, data->win);
		}
	}
}

void	move_right(t_data *data)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	if (data->map->map[y][x + 1] != '1' || (data->map->map[y][x + 1] == 'E' && \
	data->map->c_occ == 0))
	{
		data->map->moves++;
		if (data->map->map[y][x + 1] == 'C')
			data->map->c_occ--;
		if (data->map->map[y][x + 1] == 'E' && data->map->c_occ == 0)
			destroy_window(data);
		else if (data->map->map[y][x + 1] != 'E')
		{
			data->map->p_x = x + 1;
			data->map->map[y][x] = '0';
			data->map->map[y][x + 1] = 'P';
			mlx_clear_window(data->mlx, data->win);
		}
	}
}

void	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}
