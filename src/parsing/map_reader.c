/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:21:26 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 13:07:54 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// static char	*check_newline(int fd)
// {
// 	int		map_found;
// 	char	*str;

// 	map_found = 0;
// 	while (!map_found)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			return (NULL);
// 		if (!ft_strlen(str))
// 			free(str);
// 		else
// 			map_found = 1;
// 	}
// 	return (str);
// }

// static int	line_count(char *file)
// {
// 	int		col;
// 	char	*str;
// 	int		fd;

// 	fd = open(file, O_RDONLY);
// 	col = 0;
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 		{
// 			close (fd);
// 			return (col);
// 		}
// 		if (*str != '\n')
// 			col++;
// 		free(str);
// 	}
// }

int	map_reader(t_mlx *game)
{
	int			i;
	t_map_infos	*infos;

	i = 0;
	infos = get_infos();
	game->map.map = infos->map;
	game->map.nb_row = len_dbl_array(infos->map);
	game->map.len = ft_strlen(game->map.map[0]);
	return (1);
}
