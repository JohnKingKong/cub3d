/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:51:36 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/19 00:47:59 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// static int texture_init(t_mlx *game, const char **argv)
// {

	
// }

static int image_val_init(t_mlx *game)
{
	game->basic.mlx = mlx_init();
	game->basic.win = mlx_new_window(game->basic.mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->basic.mlx || !game->basic.win)
		return (print_error("MLX OR WIN FAILED INIT"));
	game->img.img = mlx_new_image(game->basic.mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		return (print_error("IMG FAILED INIT"));
	mlx_do_key_autorepeatoff(game->basic.mlx);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
						&game->img.endian);
	if (!game->img.addr)
		return (print_error("IMG BUFFER FAILED INIT"));
	return (1);
}

static int val_init(t_mlx *game,char **argv)
{
	ft_memset(game, 0, sizeof(t_mlx));
	if (!image_val_init(game))
		return (0);
	// map init .. 
	if (!map_reader(argv[1], game))
		return(print_error("MAP ERROR"));
	// texture init .. 

	return (1);
}

int main(int argc, char **argv)
{
	t_mlx game;

	if (argc != 2)
		return (print_error("Le nombre d'arguments est invalide"));
	if (!val_init(&game, argv))
		return (0);

	game_init(&game);
	return (0);
}