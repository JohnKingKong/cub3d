/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:56:15 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/25 13:04:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	mlx_destroy_image(game->basic.mlx, game->img.img);
	ft_free_chartable(game->map.map);
	mlx_hook(game->basic.win, 17, 0, (void *)exit, 0);
	exit (0);
}

void	error_exit(char *error_message)
{
	int len;

	len = ft_strlen(error_message);
	if (ft_strnstr(error_message, "argc\0", len))
		ft_printf("%sError\nMust have a map in argument\n%s",RED, GRN);
	else if (ft_strnstr(error_message, "extension\0", len))
		ft_printf("%sError\nMap must end with .cub%s\n",RED,GRN);
	else if (ft_strnstr(error_message, "just_cub\0", len))
		ft_printf("%sError\nThe name of the map cant be empty\n%s", RED, GRN);
	else if(ft_strnstr(error_message, "fake_file", len))
		ft_printf("%sError\nThe map does not exist\n%s", RED, GRN);
	exit (1);
}
