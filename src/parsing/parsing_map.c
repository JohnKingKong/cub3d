/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:59 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/18 14:33:04 by jvigneau         ###   ########.fr       */
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
	static int			i = 0;

	infos = get_infos();
		if (!is_valid_line(line))
		{
				error_exit(INV_LINE);
		}
		infos->map[i] = ft_strdup2(line);
		i++;
}

void	is_map(char *line)
{
	if (all_elem_are_true() == false)
		error_exit(ORDER);
	copy_map(line);
	
}
