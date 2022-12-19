/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:00:21 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/19 15:31:23 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	continue_free(void)
{
	int			i;
	t_map_infos	*infos;

	infos = get_infos();
	i = 0;
	if (infos->path[0])
		free(infos->path[0]);
	if (infos->path[1])
		free(infos->path[1]);
	if (infos->path[2])
		free(infos->path[2]);
	if (infos->path[3])
		free(infos->path[3]);
	free(infos);
}

void	free_parsing(void)
{
	t_map_infos	*infos;
	int			i;

	infos = get_infos();
	i = 0;
	if (infos->map)
		ft_free_chartable(infos->map);
	if (infos->color)
	{
		if (infos->color[0] && infos->color[1])
		{
			while (i <= 3)
			{
				if (infos->color[0][i])
					free(infos->color[0][i]);
				if (infos->color[1][i])
					free(infos->color[1][i]);
				i++;
			}
			free(infos->color[0]);
			free(infos->color[1]);
		}
		free(infos->color);
	}
	continue_free();
}
