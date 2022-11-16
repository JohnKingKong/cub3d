/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:59 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/31 15:05:43 by jvigneau         ###   ########.fr       */
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
	infos->map = ft_calloc(len_dbl_array(&line) + 1, sizeof(char *));
	while (line != NULL)
	{
		if (!is_valid_line(line))
		{
			if (get_next_line(infos->fd) == NULL)
				break ;
			else
				error_exit(INV_LINE);
		}
		infos->map[i] = ft_strdup2(line);
		line = get_next_line(infos->fd);
		i++;
	}
}

void	is_map(char *line)
{
	if (all_elem_are_true() == false)
		error_exit(ORDER);
	copy_map(line);
	if (!check_spawn())
		error_exit(NO_SPAWN);
	if (flood_fill() == false)
		error_exit(INV_MAP);
}
