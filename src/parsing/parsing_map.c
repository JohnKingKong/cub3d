/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:59 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/26 15:45:10 by anonymous        ###   ########.fr       */
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

static bool is_valid_line(char *line)
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

	i = 1;
	infos = get_infos();
	infos->map = ft_calloc(199, sizeof(char *));
	infos->map[0] = ft_strdup(line);
	while (line != NULL)
	{
		line = get_next_line(infos->fd);
		if (!is_valid_line(line))
		{
			if (get_next_line(infos->fd) == NULL)
				break ;
			else
				error_exit("invalid_map");
		}
		infos->map[i] = ft_strdup(line);
		i++;
	}
	infos->map[i] = NULL;
	i = 0;
	while (infos->map[i])
	{
		printf("lineee %d = %s\n", i, infos->map[i]);
		i++;
	}
}


void	is_map(char *line)
{
	if (all_elem_are_true() == false)
		error_exit("order_map");
	copy_map(line);
}