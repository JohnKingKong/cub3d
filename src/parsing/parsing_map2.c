/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:18:13 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/12 15:19:42 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_valid_map_input(char map_input)
{
	if (map_input != '0' && map_input != '1' && map_input != 'S'
		&& map_input != 'W' && map_input != 'E' && map_input != 'N'
		&& map_input != ' ')
		error_exit(INV_INPUT);
}

static void	loop_map(char map, int i, int j)
{
	t_map_infos	*infos;

	infos = get_infos();
	if (map == 'S' || map == 'N'
		|| map == 'W' || map == 'E')
	{
		if (infos->spawner == false)
		{
			infos->direction = map;
			infos->positionx = i;
			infos->positiony = j;
			infos->spawner = true;
		}
		else
			error_exit(MULT_SPAWN);
	}
	check_valid_map_input(map);
}

bool	check_spawn(void)
{
	t_map_infos	*infos;
	int			i;
	int			j;

	i = 0;
	infos = get_infos();
	while (infos->map[i])
	{
		j = 0;
		while (infos->map[i][j])
		{
			loop_map(infos->map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (infos->spawner == true)
		return (true);
	return (false);
}
