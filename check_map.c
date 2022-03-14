/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:23:33 by isabri            #+#    #+#             */
/*   Updated: 2022/03/13 16:27:26 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char	**map)
{
	int	up_down;
	int	left_right;
	int characters;
	int	width;

	up_down = check_map_borders_up_down(map);
	left_right = check_map_borders_left_right(map);
	characters = check_map_characters(map);
	width = check_width(map);
	if (!up_down || !left_right || !characters || !width)
		return (0);
	return (1);
}