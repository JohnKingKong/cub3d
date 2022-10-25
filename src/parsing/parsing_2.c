/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:07:44 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/25 15:33:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_infos(void)
{
	t_map_infos	*infos;

	infos = get_infos();
	infos->one_time_on[0] = false;
	infos->one_time_on[1] = false;
	infos->one_time_on[2] = false;
	infos->one_time_on[3] = false;
	infos->one_time_on[4] = false;
	infos->one_time_on[5] = false;
	infos->color = calloc(3, sizeof(char **));
}

static void populate_color(int index, char *line)
{
	t_map_infos	*infos;
	int			i;
	int			j;
	int			k;

	i = 0;
	if (line)
		j = 0;
	k = 0;
	if (index == 4)
		j = 0;
	else if (index == 5)
		j = 1;
	infos = get_infos();
	infos->color[j]= ft_calloc(4, sizeof(char *));
	while (k <= 3)
	{
		while (line[i] && line[i] != ',' && !ft_isspace(line[i]))
			i++;
		infos->color[j][k] = ft_calloc(i+1, sizeof(char));
		ft_strlcpy(infos->color[j][k], line, i+1);
		line+=i+1;
		k++;
		i = 0;
	}
}

static void	populate_text(char *line, int index)
{
	t_map_infos	*infos;
	int			len;

	infos = get_infos();
	len = 0;
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
	{
		while (line[len] != '\n')
		len++;
		infos->path[index] = ft_calloc(len + 2, sizeof(char));
		ft_strlcpy(infos->path[index], line, len + 1);
		len = 0;
	}
	else
		populate_color(index, line);

}

static void	loop_gnl(int fd)
{
	char		*line;
	t_map_infos	*infos;

	infos = get_infos();
	line = get_next_line(fd);

	while (line != NULL)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (line[0] == 'N' && line[1] == 'O' )
			populate_text(line, 0);
		else if (line[0] == 'S' && line[1] == 'O')
			populate_text(line, 1);
		else if (line[0] == 'W' && line[1] == 'E')
			populate_text(line, 2);
		else if (line[0] == 'E' && line[1] == 'A')
			populate_text(line, 3);
		else if (line[0] == 'F')
			populate_text(line, 4);
		else if (line[0] == 'C')
			populate_text(line, 5);
		line = get_next_line(fd);
	}
	printf("infos :%s so :%s we :%s ea :%s\n", infos->path[0],infos->path[1], infos->path[2], infos->path[3]);
	printf("color1 :%s 2 :%s 3 :%s color2 1 :%s 2 :%s 3 :%s\n", infos->color[0][0], infos->color[0][1], infos->color[0][2], infos->color[1][0], infos->color[1][1], infos->color[1][2]);
}

void	check_elements(char *file)
{
	int			fd;
	t_map_infos	*infos;

	fd = open (file, O_RDONLY);
	infos = get_infos();
	if (infos)
		init_infos();
	loop_gnl(fd);

}

t_map_infos	*get_infos(void)
{
	static t_map_infos	*infos = NULL;

	if (infos == NULL)
		infos = ft_calloc(1, sizeof(t_map_infos));
	return (infos);
}