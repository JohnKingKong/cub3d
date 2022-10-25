/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:32:45 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/25 17:55:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CUB3D_H
# define P_CUB3D_H

# include "s_cub3d.h"

int		print_error(char *str);
int		map_reader(char *file, t_mlx *game);
void	ft_exit(t_mlx *game);
void	game_init(t_mlx *game);
int		move(int keycode, t_mlx *game);
void	draw_grid(t_mlx *game);
float	convert_deg_rad(float deg);
float	convert_rad_deg(float rad);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	normalize_angle(float angle);
int		get_pixel(t_data *data, int x, int y);

//Parsing Functions
bool		start_parse(char *argv[], int argc);
void		check_elements(char *file);
void		is_map(char *line);

// Map infos singleton
t_map_infos	*get_infos(void);
void		init_infos(void);

//Error Functions
void	error_exit(char *error_message);


#endif