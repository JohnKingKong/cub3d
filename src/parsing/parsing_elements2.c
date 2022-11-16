/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:18:13 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/31 14:31:14 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_color(int index, char *line)
{
	t_map_infos	*infos;
	int			i;
	int			j;

	j = 0;
	infos = get_infos();
	infos->color[index - 4] = ft_calloc(4, sizeof(char *));
	while (j <= 3)
	{
		i = 0;
		while (line[i] && line[i] != ',' && !ft_isspace(line[i]))
			i++;
		infos->color[index - 4][j] = ft_calloc(i + 1, sizeof(char));
		ft_strlcpy(infos->color[index - 4][j], line, i + 1);
		line += i + 1;
		j++;
	}
}

void	set_path(char *line, int index)
{
	int			len;
	t_map_infos	*infos;

	len = 0;
	infos = get_infos();
	while (line[len] != '\n')
		len++;
	infos->path[index] = ft_calloc(len + 2, sizeof(char));
	ft_strlcpy(infos->path[index], line, len + 1);
}
