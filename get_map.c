/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:42:10 by isabri            #+#    #+#             */
/*   Updated: 2022/03/13 20:15:28 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_num_lines(int fd)
{
	int		lines;
	char	*ptr;

	lines = 0;
	ptr = get_next_line(fd);
	while (ptr)
	{
		lines++;
		free(ptr);
		ptr = NULL;
		ptr = get_next_line(fd);
	}
	return (lines);
}

char	**get_map(int lines, int fd)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (0);
	map[lines] = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}

int	main(void)
{
	int		fd;
	char	**map;
	int		lines;

	fd = open("./map.ber", O_RDONLY);
	lines = get_num_lines(fd);
	close(fd);
	fd = open("./map.ber", O_RDONLY);
	map = get_map(lines, fd);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; map[i][j]; j++)
			printf("%c", map[i][j]);
	}
	if (check_map(map))
		printf("\nNAAADI\n");
	else
		printf("\nKHAAAAARI\n");
}
