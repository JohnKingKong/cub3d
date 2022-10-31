/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:00:21 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/31 16:11:28 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_parsing(void)
{
	t_map_infos	*infos;
	int			i;

	infos = get_infos();
	ft_free_chartable(infos->map);
	i = 0;
	while (infos->color[i])
	{
		free(infos->color[i]);
		i++;
	}
	free(infos->color);
	// i = 0;
	// while (infos->path[i])
	// {
	// 	free(infos->path[i]);
	// 	i++;
	// }
}
