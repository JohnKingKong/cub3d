/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:59 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/25 18:05:55 by anonymous        ###   ########.fr       */
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

void	is_map(char *line)
{
	if (all_elem_are_true() == false)
		error_exit("order_map");
}
