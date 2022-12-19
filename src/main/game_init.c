/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:39 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 11:59:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	game_init(t_mlx *game)
{
	mlx_hook(game->basic.win, 2, 0, move, game);
	mlx_loop_hook(game->basic.mlx, move_player, game);
	mlx_hook(game->basic.win, 3, 0, check_key_is_on, game);
	mlx_hook(game->basic.win, 17, 0, (void *)exit, 0);
	mlx_loop(game->basic.mlx);
}

void	init_infos(void)
{
	t_map_infos	*infos;

	infos = get_infos();
	infos->spawner = false;
	infos->one_time_on[0] = false;
	infos->one_time_on[1] = false;
	infos->one_time_on[2] = false;
	infos->one_time_on[3] = false;
	infos->one_time_on[4] = false;
	infos->one_time_on[5] = false;
	infos->color = calloc(3, sizeof(char **));
	infos->map = ft_calloc(10000 + 1, sizeof(char *));
}

t_map_infos	*get_infos(void)
{
	static t_map_infos	*infos = NULL;

	if (infos == NULL)
		infos = ft_calloc(1, sizeof(t_map_infos));
	return (infos);
}
