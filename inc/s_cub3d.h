/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:32:47 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/26 13:06:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUB3D_H
# define S_CUB3D_H

# include <stdbool.h>

typedef struct	s_v
{
	float		x;
	float		y;
}				t_v;

typedef struct	s_ray
{
	t_v			side_delta;
	float		dist;
	int			hit_down;
	int			hit_left;
}				t_ray;


typedef struct	s_key_b
{
	int			d;
	int			a;
	int			s;
	int			w;
}				t_key_b;


typedef struct	s_dda
{
	t_v 	step_size;
	t_v 	ray_lenght;
	t_v 	step;
	t_v 	ray_dir;

}				t_dda;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	float		img_width;
	float		img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_texture
{
	t_data		nort;
	t_data		south;
	t_data		west;
	t_data		east;
	t_data		door;
	t_data		floor;
	t_data		celling;
}				t_texture;

typedef struct	s_map
{
	int			len;
	int			nb_row;
	char		**map;
}				t_map;

typedef struct s_basic
{
	void		*mlx;
	void		*win;
}	t_basic;

typedef struct s_map_infos
{
	int		fd;
	bool	one_time_on[6];
	char	*path[4];
	char	**map;
	char	***color;
}	t_map_infos;

typedef struct s_mlx
{
	t_basic		basic;
	t_data		img;
	t_map		map;
	t_texture	texture;
	t_key_b		key_hook;
	int			frames;
}	t_mlx;

#endif