/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:39 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/19 01:10:49 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void game_init(t_mlx *game)
{

	draw_grid(game); // a enlever 
	mlx_hook(game->basic.win, 2, 0, move, game);
	mlx_hook(game->basic.win, 17, 0, (void *)exit, 0);
	mlx_loop(game->basic.mlx);	
}