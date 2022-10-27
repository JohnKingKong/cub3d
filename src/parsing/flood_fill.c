/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:03:18 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/27 12:26:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_up(char **map, int i, int j)
{
	while (map[i][j] && i >= 0)
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ' || i < 1)
			break ;
		i--;
	}
	return (false);
}

static bool	check_down(char **map, int i, int j)
{
	int	size;

	size = len_dbl_array(map);
	while (map[i][j] && i < size)
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ')
			break ;
		i++;
	}
	return (false);
}

static bool	check_right(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ')
			break ;
		j++;
	}
	return (false);
}

static bool	check_left(char **map, int i, int j)
{
	while (map[i][j] && j >= 0)
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ')
			break ;
		j--;
	}
	return (false);
}

bool	flood_fill(void)
{
	t_map_infos	*infos;
	int			i;
	int			j;

	infos = get_infos();
	i = 0;
	while (infos->map[i])
	{
		j = 0;
		while (infos->map[i][j])
		{
			if (infos->map[i][j] == '0')
			{
				if (!check_up(infos->map, i, j) || !check_down(infos->map, i, j)
					|| !check_right(infos->map, i, j) || !check_left(infos->map, i, j))
						error_exit("invalid_map");
			}
			j++;
		}
		i++;
	}
	return (true);
}