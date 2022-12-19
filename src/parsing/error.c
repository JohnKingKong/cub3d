/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:56:15 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 13:53:48 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	print_error(char *str)
{
	if (str)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(str, 2);
	}
	return (0);
}

void	ft_exit(t_mlx *game)
{
	free_parsing();
	if (game->ray)
		free(game->ray);
	mlx_destroy_image(game->basic.mlx, game->img.img);
	mlx_hook(game->basic.win, 17, 0, (void *)exit, 0);
	exit (0);
}

void	error_exit(char *error_message)
{
	t_map_infos	*infos;

	infos = get_infos();
	free_parsing();
	printf("%sError\n", RED);
	printf("%s%s", error_message, GRN);
	exit (1);
}
