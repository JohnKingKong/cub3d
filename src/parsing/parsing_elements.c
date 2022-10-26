/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:07:44 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/26 13:08:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void set_color(int index, char *line)
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

static void set_path(char *line, int index)
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

static void	prep_line(char *line, int index)
{
	t_map_infos	*infos;

	infos = get_infos();
	if (infos->one_time_on[index] == true)
		error_exit("duplicate");
	infos->one_time_on[index] = true;
	if (index >= 0 && index <=3)
		line+=2;
	else
		line++;
	while (*line && ft_isspace(*line))
		line++;
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
	char		*line;
	int			i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		is_element(line);
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '1')
			is_map(line);
		line = get_next_line(fd);
	}
}

void	check_elements(char *file)
{
	t_map_infos	*infos;

	infos = get_infos();
	init_infos();
	infos->fd = open (file, O_RDONLY);
	loop_gnl(infos->fd);
	printf("no :%s\nso :%s\nwe :%s\nea :%s\n", infos->path[0],infos->path[1], infos->path[2], infos->path[3]);
	printf("color1 R :%s G :%s B :%s\ncolor2 R :%s G :%s B :%s\n", infos->color[0][0], infos->color[0][1], infos->color[0][2], infos->color[1][0], infos->color[1][1], infos->color[1][2]);
}
