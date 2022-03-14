/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:41:52 by isabri            #+#    #+#             */
/*   Updated: 2022/03/14 12:47:07 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct t_map{
	char	**map;
	int		height;
	int		width;
	int		P;
	int		E;
	int		C;
}	s_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *s);
char	**get_map(int lines, int fd);
int		get_num_lines(int fd);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		check_map_characters(char **map);
int		check_map_borders_up_down(char **map);
int		check_map_borders_left_right(char **map);
int		check_width(char **map);
int		check_map(char	**map);

#endif