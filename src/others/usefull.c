/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:52:08 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/15 19:34:03 by jmorneau         ###   ########.fr       */
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
				my_mlx_pixel_put(&game->img, j++ + x, i + y, GRAY);
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
	t_map_infos *infos;

	infos = get_infos();





	i = 0;
	
	int x = ft_strlen(infos->map[0]);
	int y = len_dbl_array(infos->map);
	for (int i = 0; i < y; i++)
	printf("%s\n", infos->map[i]);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (infos->map[i][j] == '1')
				draw_square(game, j * 64, i * 64, BLACK);
			else
				draw_square(game, j * 64, i * 64, WHITE);
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