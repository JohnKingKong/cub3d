/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:21:26 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 16:16:09 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_reader(t_mlx *game)
{
	int			i;
	t_map_infos	*infos;

	i = 0;
	infos = get_infos();
	game->map.map = infos->map;
	game->map.nb_row = len_dbl_array(infos->map);
	game->map.len = ft_strlen(game->map.map[0]);
	return (1);
}
