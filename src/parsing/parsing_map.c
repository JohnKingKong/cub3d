/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:59 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/27 12:52:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	all_elem_are_true(void)
{
	t_map_infos	*infos;
	int			i;

	i = 0;
	infos = get_infos();
	while (i <= 5)
	{
		if (infos->one_time_on[i] == false)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (false);
	return (true);
}

static void	copy_map(char *line)
{
	t_map_infos	*infos;
	int			i;

	i = 0;
	infos = get_infos();
	infos->map = ft_calloc(199, sizeof(char *));
	while (line != NULL)
	{
		if (!is_valid_line(line))
		{
			if (get_next_line(infos->fd) == NULL)
				break ;
			else
				error_exit("invalid_line");
		}
		infos->map[i] = ft_strdup2(line);
		line = get_next_line(infos->fd);
		i++;
	}
}

static void	check_valid_map_input(char map_input)
{
	if (map_input != '0' || map_input != '1' || map_input != 'S'
		|| map_input != 'W' || map_input != 'E' || map_input != 'N'
		|| map_input != ' ')
			error_exit("invalid_input");
}

static bool	check_spawn()
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
			if (infos->map[i][j] == 'S' || infos->map[i][j] == 'N'
				|| infos->map[i][j] == 'W' || infos->map[i][j] == 'E')
			{
				if (infos->spawner == false)
					infos->spawner = true;
				else
					error_exit("multiple_spawn");
			}
			check_valid_map_input(map[i][j]);
			j++;
		}
		i++;
	}
	if (infos->spawner == true)
		return (true);
	return (false);
}

void	is_map(char *line)
{
	if (all_elem_are_true() == false)
		error_exit("order_map");
	copy_map(line);
	if (!check_spawn())
		error_exit("no_spawn");
	if (flood_fill() == false)
		error_exit("invalid_map");
}
