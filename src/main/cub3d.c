/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:51:36 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 15:10:56 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

static	int	var_texture_init(t_data *img,
			char *img_name, char *path, t_mlx *game)
{
	char	*temp;
	char	*temp2;

	img->img = mlx_xpm_file_to_image(game->basic.mlx,
			path, &img->img_width, &img->img_height);
	if (!img->img)
	{
		temp = ft_strdup2(img_name);
		temp2 = ft_strjoin(temp, " XPM TEXTURE FAILED INIT\n");
		print_error(temp2);
		free(temp2);
		free(temp);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		return (print_error("XPM BUFFER FAILED INIT"));
	return (1);
}

static int	texture_init(t_mlx *game)
{
	t_map_infos	*infos;

	infos = get_infos();
	if (!var_texture_init(&game->texture.north,
			"NORTH", infos->path[0], game))
		return (0);
	if (!var_texture_init(&game->texture.south,
			"SOUTH", infos->path[1], game))
		return (0);
	if (!var_texture_init(&game->texture.east,
			"EAST", infos->path[2], game))
		return (0);
	if (!var_texture_init(&game->texture.west,
			"WEST", infos->path[3], game))
		return (0);
	return (1);
}

static int	image_val_init(t_mlx *game)
{
	game->basic.mlx = mlx_init();
	game->basic.win = mlx_new_window(game->basic.mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->basic.mlx || !game->basic.win)
		return (print_error("MLX OR WIN FAILED INIT"));
	game->img.img = mlx_new_image(game->basic.mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		return (print_error("IMG FAILED INIT"));
	mlx_do_key_autorepeatoff(game->basic.mlx);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!game->img.addr)
		return (print_error("IMG BUFFER FAILED INIT"));
	game->ray = calloc(sizeof(t_ray), NUM_RAY);
	if (!game->ray)
		return (print_error("MALLOC FAILED"));
	return (1);
}

static int	val_init(t_mlx *game)
{
	t_map_infos	*infos;

	infos = get_infos();
	ft_memset(game, 0, sizeof(t_mlx));
	game->player.player_angle = player_position(infos->direction);
	game->player.pos.x = (infos->positionx * 64) + 32;
	game->player.pos.y = (infos->positiony * 64) + 32;
	game->player.rotation_speed = 0.0523599;
	game->player.walk_speed = 3;
	if (!image_val_init(game))
		return (0);
	if (!map_reader(game))
		return (print_error("MAP ERROR"));
	if (!texture_init(game))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_mlx	game;

	if (start_parse(argv, argc) == false)
		error_exit("parse");
	if (!val_init(&game))
		ft_exit(&game);
	game_init(&game);
	free_parsing();
	return (0);
}
