/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:27:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/19 15:25:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_path_texture(char *path)
{
	char	*temp;

	temp = ft_strdup2(path);
	if (access(temp, F_OK) < 0)
	{
		free(temp);
		return (false);
	}
	free(temp);
	return (true);
}

static void	prep_line(char *line, int index)
{
	t_map_infos	*infos;

	infos = get_infos();
	if (infos->one_time_on[index] == true)
		error_exit(DUPL);
	infos->one_time_on[index] = true;
	if (index >= 0 && index <= 3)
		line += 2;
	else
		line++;
	while (*line && ft_isspace(*line))
		line++;
	if (index <= 3 && check_path_texture(line) == false)
		error_exit(INV_TEXTURE);
	if (index >= 0 && index <= 3)
		set_path(line, index);
	else
		set_color(index, line);
}

static void	is_element(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (line[0] == 'N' && line[1] == 'O' )
		prep_line(line, 0);
	else if (line[0] == 'S' && line[1] == 'O')
		prep_line(line, 1);
	else if (line[0] == 'W' && line[1] == 'E')
		prep_line(line, 2);
	else if (line[0] == 'E' && line[1] == 'A')
		prep_line(line, 3);
	else if (line[0] == 'F')
		prep_line(line, 4);
	else if (line[0] == 'C')
		prep_line(line, 5);
}

static void	loop_gnl(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		error_exit(EMPTY_FILE);
	while (line != NULL)
	{
		i = 0;
		is_element(line);
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '1')
			is_map(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	check_elements(char *file)
{
	t_map_infos	*infos;

	infos = get_infos();
	init_infos();
	infos->fd = open (file, O_RDONLY);
	loop_gnl(infos->fd);
	if (!check_spawn())
		error_exit(NO_SPAWN);
	if (flood_fill() == false)
		error_exit(INV_MAP);
}
