/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:21:26 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/21 13:59:33 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

static char	*check_newline(int fd)
{
	int		map_found;
	char	*str;

	map_found = 0;
	while (!map_found)
	{
		str = get_next_line(fd);
		if (!str)
			return (NULL);
		if (!ft_strlen(str))
			free(str);
		else
			map_found = 1;
	}
	return (str);
}

static int	line_count(char *file)
{
	int		col;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	col = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			close (fd);
			return (col);
		}
		if (*str != '\n')
			col++;
		free(str);
	}
}

int	map_reader(char *file, t_mlx *game)
{
	int	fd;
	int	i;

	i = 0;
	game->map.nb_row = line_count(file);
	game->map.map = ft_calloc(sizeof(char *), game->map.nb_row + 1);
	fd = open(file, O_RDONLY);
	game->map.map[0] = check_newline(fd);
	while (++i < game->map.nb_row)
		game->map.map[i] = get_next_line(fd);
	game->map.map[i] = NULL;
	game->map.len = ft_strlen(game->map.map[0]);
	close(fd);
	return (1);
}
