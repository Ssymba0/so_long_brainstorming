/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:08 by isabri            #+#    #+#             */
/*   Updated: 2022/03/31 18:54:17 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!haystack)
		return (NULL);
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[++i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
	}
	return (0);
}

int	get_fd(int ac, char *av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("ERROR\nusage: ./so_long \"map.ber\"\n");
		exit(0);
	}
	if (!ft_strnstr(av, ".ber"))
	{
		ft_printf("ERROR\nusage:./so_long \"map.ber\"\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av, O_RDONLY);
	return (fd);
}
