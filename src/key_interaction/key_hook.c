/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:43:10 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/12 15:34:08 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

int	move_player(t_mlx *game)
{
	if (game->key_hook.a)
			game->player.player_angle += game->player.rotation_speed;
	if (game->key_hook.d)
			game->player.player_angle -= game->player.rotation_speed;
	if (game->key_hook.w)
	{
		game->player.pos.x += cos(game->player.player_angle)
			* game->player.walk_speed;
		game->player.pos.y -= sin(game->player.player_angle)
			* game->player.walk_speed;
	}
	if (game->key_hook.s)
	{
		game->player.pos.x -= cos(game->player.player_angle)
			* game->player.walk_speed;
		game->player.pos.y += sin(game->player.player_angle)
			* game->player.walk_speed;
	}	
	ft_memset(game->img.addr, 0, WIDTH * HEIGHT * game->img.bits_per_pixel / 8);
	draw_fov(game);
	return (0);
}

int	move(int keycode, t_mlx *game)
{	
	if (keycode == A)
		game->key_hook.a = 1;
	else if (keycode == D)
		game->key_hook.d = 1;
	else if (keycode == W)
		game->key_hook.w = 1;
	else if (keycode == S)
		game->key_hook.s = 1;
	else if (keycode == SHIFT)
	{
		game->player.walk_speed = 6;
		game->player.rotation_speed *= 1.5;
	}
	if (keycode == ESC)
		ft_exit(game);
	return (0);
}

int	check_key_is_on(int keycode, t_mlx *game)
{
	if (keycode == A)
		game->key_hook.a = 0;
	else if (keycode == D)
		game->key_hook.d = 0;
	else if (keycode == W)
		game->key_hook.w = 0;
	else if (keycode == S)
		game->key_hook.s = 0;
	else if (keycode == SHIFT)
	{
		game->player.walk_speed = 3;
		game->player.rotation_speed /= 1.5;
	}
	return (0);
}
