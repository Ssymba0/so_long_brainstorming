/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:52:47 by isabri            #+#    #+#             */
/*   Updated: 2022/03/31 18:56:39 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef IMG_W
#  define IMG_W 50
# endif
# ifndef IMG_H
#  define IMG_H 50
# endif
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		p_occ;
	int		c_occ;
	int		e_occ;
	int		p_x;
	int		p_y;
	int		moves;
}	t_map;

typedef struct s_obj
{
	void	*w;
	void	*c;
	void	*p;
	void	*d;
	void	*e;
	char	*wpath;
	char	*cpath;
	char	*ppath;
	char	*dpath;
	char	*epath;
}	t_obj;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_obj	*img;
}	t_data;

t_map	*init_map(void);
void	get_map(t_map *map, int ac, char *av);
int		get_fd(int ac, char *av);
char	*ft_strnstr(const char *haystack, const char *needle);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_new(char *str);
char	*ft_gl(char *str);
char	*gnl_read(int fd, char *str);
char	*ft_strnstr(const char *haystack, const char *needle);
int		ft_strchr(char	*s, char c);
void	read_map_coord(int fd, t_map *map);
void	map_alloc(t_map *map);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		check_shape(t_map *map);
int		check_top_bot(t_map *map);
int		check_borders(t_map	*map);
int		check_content(t_map *map);
int		check_map(t_map *map);
void	init_mlx(t_mlx *mlx, t_obj *img);
int		moves(int keycode, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	get_player(t_map *map);
void	get_coins(t_map *map);
void	get_exit(t_map *map);
void	draw_map(t_obj *img, void *mlx, void *win, t_map *map);
void	destroy_window(t_data *data);

#endif