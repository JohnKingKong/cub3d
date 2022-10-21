/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:52:08 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/21 14:24:54 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

float convert_deg_rad(float deg)
{
	return (deg * (PI / 180.0));
}

float convert_rad_deg(float rad)
{
	return (rad * (180 / PI));
}

void draw_square(t_mlx *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if ((i == 0 || j == 0 || i == 63 || j == 63))
				my_mlx_pixel_put(&game->img, j++ + x, i + y, GRANITE_GREY);
			else
				my_mlx_pixel_put(&game->img, j++ + x, i + y, color);
		}
		i++;
	}
}

void draw_grid(t_mlx *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.nb_row)
	{
		j = 0;
		while (j < game->map.len)
		{
			if (game->map.map[i][j] == '1')
				draw_square(game, j * 64, i * 64, BLACK_BLUE);
			else
				draw_square(game, j * 64, i * 64, WHITE_ALUMINUM);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->basic.mlx, game->basic.win, game->img.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0 || color == INV)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}