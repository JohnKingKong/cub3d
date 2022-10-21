/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:56:15 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/19 00:50:21 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int print_error(char *str)
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
	mlx_destroy_image(game->basic.mlx, game->img.img);
	ft_free_chartable(game->map.map);
	mlx_hook(game->basic.win, 17, 0, (void *)exit, 0);
	exit (0);
}