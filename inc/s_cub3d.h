/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:32:47 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 13:25:22 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUB3D_H
# define S_CUB3D_H

# include <stdbool.h>

typedef struct s_v
{
	float		x;
	float		y;
}				t_v;

typedef struct s_ray
{
	float		dist;
	float		ray_angle;
	int			hit_down;
	int			hit_left;
	union
	{
		float	delta_x;
		float	delta_y;
	};
}				t_ray;

typedef struct s_key_b
{
	int			d;
	int			a;
	int			s;
	int			w;
}				t_key_b;

typedef struct s_dda
{
	t_v		delta;
	t_v		dist_step;
	t_v		m;
}				t_dda;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_data;

typedef struct s_three
{
	float	line_h;
	float	ty_step;
	float	line_o;
	float	ty_off;
	float	step_x;
	float	step_y;
}				t_three;

typedef struct s_texture
{
	t_data		north;
	t_data		south;
	t_data		west;
	t_data		east;
}				t_texture;

typedef struct s_map
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

typedef struct s_player
{
	t_v			pos;
	float		walk_speed;
	float		rotation_speed;
	float		player_angle;
}				t_player;

typedef struct s_map_infos
{
	int		fd;
	bool	spawner;
	bool	one_time_on[6];
	char	direction;
	int		positionx;
	int		positiony;
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
	t_ray		*ray;
	t_player	player;
	int			frames;
}	t_mlx;

#endif
