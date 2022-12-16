/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:59:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/12 15:31:43 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	three_d(t_mlx *game, int x)
{
	t_three	three;

	ft_memset(&three, 0, sizeof(three));
	game->ray[x].dist = game->ray[x].dist
		* cos(game->ray[x].ray_angle - game->player.player_angle);
	print_texture(game, &three, x);
}

void	draw_fov(t_mlx *game)
{
	float	cangle;
	float	j;
	int		i;

	cangle = game->player.player_angle;
	j = cangle - FOV_ANGLE;
	i = 0;
	while (cangle > j)
	{
		game->ray[i] = dda_v2(game, cangle + (FOV_ANGLE / 2));
		three_d(game, i);
		cangle -= FOV_ANGLE / NUM_RAY;
		i++;
	}
	mlx_put_image_to_window(game->basic.mlx,
		game->basic.win, game->img.img, 0, 0);
}
