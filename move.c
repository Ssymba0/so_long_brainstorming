/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:32 by isabri            #+#    #+#             */
/*   Updated: 2022/03/24 12:11:42 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int keycode, t_data *data)
{
	if (keycode == 13)
		move_up(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 2)
		move_right(data);
	else if (keycode == 53)
		destroy_window(data);
	draw_map(data->img, data->mlx, data->win, data->map);
	return (0);
}
