/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:44:20 by isabri            #+#    #+#             */
/*   Updated: 2022/03/13 20:30:27 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_width(char **map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(*map);
	if (map)
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
				j++;
			if (!map[i + 1])
				j++;
			if (j != len)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	check_map_borders_left_right(char **map)
{
	int	i;
	int	len;
	int	j;

	i = 1;
	len = ft_strlen(*map);
	if (!map)
		return (0);
	while (map[i] || (map[i] && !map[i + 1]))
	{
		if (map[i][0] == '1' && map[i][len - 2] == '1')
			i++;
		else if (map[i][0] == '1' && map[i][len - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_map_borders_up_down(char **map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			len = ft_strlen(map[i]);
			if (i == 0 || (map[i] && !map[i + 1]))
			{
				j = 0;
				while (map[i][j])
				{
					if (map[i][j] == '1' || map[i][len - 1] == '\n')
						j++;
					else
						return (0);
				}
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	check_map_characters(char **map)
{
	int	used[256];
	int	i;
	int	j;

	i = 0;
	while (i < 256)
		used[i++] = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0' \
			&& map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != '\n')
				return (0);
			used[(unsigned char)map[i][j]] += 1;
			j++;
		}
		i++;
	}
	if (used['E'] == 0 || used['C'] == 0 || used['P'] != 1)
		return (0);
	return (1);
}