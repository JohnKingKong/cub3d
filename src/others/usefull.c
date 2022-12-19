/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:52:08 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 11:22:29 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

float	convert_deg_rad(float deg)
{
	return (deg * (PI / 180.0));
}

float	convert_rad_deg(float rad)
{
	return (rad * (180 / PI));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0 || color == INV)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	if (x >= data->img_width || x < 0 || y >= data->img_height || y < 0)
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

float player_position(char c)
{
	if (c == 'N')
		return (QUART_PI);
	if (c == 'S')
		return (QUART3_PI);
	if (c == 'W')
		return (PI);
	if (c == 'E')
		return (TWO_PI);
	return (0);
}