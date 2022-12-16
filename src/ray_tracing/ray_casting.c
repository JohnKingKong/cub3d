/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:05:51 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/16 15:08:23 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_walls(t_mlx *game, int x, int y)
{
	if (x < 0 || x > (game->map.len) - 1 || y < 0 || y > (game->map.nb_row) - 1)
		return (1);
	if (game->map.map[y][x] == '1')
		return (1);
	return (0);
}

static void	loop_check_walls(t_dda *dda, t_mlx *game)
{
	while (1)
	{
		dda->m.x = (int)(dda->delta.x) >> 6;
		dda->m.y = ((int)(dda->delta.y) >> 6);
		if (check_walls(game, dda->m.x, dda->m.y))
			break ;
		dda->delta.x += dda->dist_step.x;
		dda->delta.y += dda->dist_step.y;
	}
}

static void	dda_var_init_h(float angle, t_dda *dda, t_mlx *game, t_ray *ray)
{
	float	a_tan;

	a_tan = -1 / tan(angle);
	if (angle < PI)
	{
		dda->delta.y = (((int)game->player.pos.y >> 6) << 6) - 0.0001;
		dda->dist_step.y = -64;
	}
	else
	{
		dda->delta.y = (((int)game->player.pos.y >> 6) << 6) + 64;
		dda->dist_step.y = 64;
		ray->hit_down = 1;
		ray->hit_left = 1;
	}
	dda->dist_step.x = dda->dist_step.y * a_tan;
	dda->delta.x = game->player.pos.x
		- ((game->player.pos.y - dda->delta.y) * a_tan);
	loop_check_walls(dda, game);
	ray->dist = sqrtf(((dda->delta.x - game->player.pos.x)
				* (dda->delta.x - game->player.pos.x))
			+ ((dda->delta.y - game->player.pos.y)
				* (dda->delta.y - game->player.pos.y)));
	ray->delta_x = dda->delta.x;
}

static void	dda_var_init_v(float angle, t_dda *dda, t_mlx *game, t_ray *ray)
{
	float	a_tan;

	a_tan = -tan(angle);
	if (angle > QUART_PI && angle < QUART3_PI)
	{
		dda->delta.x = (((int)game->player.pos.x >> 6) << 6) - 0.0001;
		dda->dist_step.x = -64;
		ray->hit_down = 1;
	}
	else
	{
		dda->delta.x = (((int)game->player.pos.x >> 6) << 6) + 64;
		dda->dist_step.x = 64;
		ray->hit_left = 1;
	}
	dda->dist_step.y = dda->dist_step.x * a_tan;
	dda->delta.y = game->player.pos.y
		- ((game->player.pos.x - dda->delta.x) * a_tan);
	loop_check_walls(dda, game);
	ray->dist = sqrtf(((dda->delta.x - game->player.pos.x)
				* (dda->delta.x - game->player.pos.x))
			+ ((dda->delta.y - game->player.pos.y)
				* (dda->delta.y - game->player.pos.y)));
	ray->delta_y = dda->delta.y;
}

t_ray	dda_v2(t_mlx *game, float angle)
{
	t_dda	dda_h;
	t_dda	dda_v;
	t_ray	ray_h;
	t_ray	ray_v;

	angle = normalize_angle(angle);
	ft_memset(&ray_h, 0, sizeof(t_ray));
	ft_memset(&ray_v, 0, sizeof(t_ray));
	dda_var_init_h(angle, &dda_h, game, &ray_h);
	dda_var_init_v(angle, &dda_v, game, &ray_v);
	if ((ray_v.dist) < (ray_h.dist))
	{
		ray_h = ray_v;
		dda_h = dda_v;
	}
	ray_h.ray_angle = angle;
	return (ray_h);
}
