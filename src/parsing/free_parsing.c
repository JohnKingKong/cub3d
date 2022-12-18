/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:00:21 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/17 14:24:50 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_parsing(void)
{
	t_map_infos	*infos;
	int			i;

	infos = get_infos();
	i = 0;
	ft_free_chartable(infos->map);
	while (i < 3)
	{
		free(infos->color[0][i]);
		free(infos->color[1][i]);
		i++;
	}
	free(infos->color[0]);
	free(infos->color[1]);
	free(infos->color);
	free(infos->path[0]);
	free(infos->path[1]);
	free(infos->path[2]);
	free(infos->path[3]);
}
