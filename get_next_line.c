/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:39:01 by isabri            #+#    #+#             */
/*   Updated: 2022/03/13 17:48:04 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_new(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i += 1;
	s = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	return (s);
}

char	*ft_gl(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = ft_substr(str, 0, i + 1);
	return (s);
}

char	*gnl_read(int fd, char *str)
{
	char	*buf;
	int		r;

	r = 1;
	buf = (char *)malloc(sizeof(char) * 2);
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && r)
	{
		r = read(fd, buf, 1);
		if (r == -1)
		{
			free(buf);
			return (0);
		}
		buf[r] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*str;

	if (fd < 0)
		return (0);
	str = gnl_read(fd, str);
	if (!str)
		return (NULL);
	ret = ft_gl(str);
	str = ft_new(str);
	return (ret);
}
