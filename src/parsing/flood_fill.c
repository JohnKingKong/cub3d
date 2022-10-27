/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:03:18 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/26 20:13:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_up(char **map, int i, int j)
{
	while(ft_isspace(map[i][j]))
		j++;
	while (i >= 0 && map[i][j])
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ' && map[i - 1] && map[i - 1][j]
			&& map[i - 1][j] != '1')
			return (false);
		i--;
	}
	return (false);
}

static bool	check_down(char **map, int i, int j)
{
	int	size;

	size = len_dbl_array(map);
	while(ft_isspace(map[i][j]))
		j++;
	while (i < size  && map[i][j])
	{
		if (map[i][j] == '1')
			return (true);
		if (map[i][j] == ' ' && map[i + 1] && map[i + 1][j]
			&& map[i + 1][j] != '1')
			return (false);
		i++;
	}
	return (false);
}

/*static bool	check_right(char **map, int i, int j)
{
	while(ft_isspace(*map[i]))
		map[i]++;
	while (map[i][j])
	{
		if (map[i][j] == ' ' && map[i][j + 1] && map[i][j + 1] != '1')
			return (false);
		if (map[i][j] == '1')
			return (true);
		i++;
	}
	return (false);
}
*/
bool	flood_fill(void)
{
	t_map_infos	*infos;
	int			i;
	int			j;
	char	**map;

	infos = get_infos();
	i = 0;
	map = ft_cpy_dbl_arr(infos->map);
	while (infos->map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				break ;
			if (!check_up(map, i, j) || !check_down(map, i, j)
				|| !check_right(map, i, j))
				error_exit("invalid_map");
			j++;
		}
		i++;
	}
	return (true);
}