/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:33:17 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/17 14:01:12 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_dot_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!ft_strnstr(filename, ".cub", len) || filename[len -4] != '.')
		return (false);
	if (len == 4)
		error_exit(JUST_CUB);
	return (true);
}

static bool	check_file_exists(char *filename)
{
	t_map_infos	*infos;

	infos = get_infos();
	infos->fd = open(filename, O_RDONLY);
	if (infos->fd < 0)
		return (false);
	close(infos->fd);
	return (true);
}

static void	print_parse_infos(void)
{
	t_map_infos	*infos;

	infos = get_infos();
	printf("infos :%s so :%s we :%s ea :%s\n",
		infos->path[0], infos->path[1], infos->path[2], infos->path[3]);
	printf("color1 :%s 2 :%s 3 :%s color2 1 :%s 2 :%s 3 :%s\n",
		infos->color[0][0], infos->color[0][1], infos->color[0][2],
		infos->color[1][0], infos->color[1][1], infos->color[1][2]);
	printf("direction = %c, position x = %d, postion y = %d\n",
		infos->direction, infos->positionx, infos->positiony);
}

bool	start_parse(char *argv[], int argc)
{
	if (argc != 2)
		error_exit(ARGC);
	if (!check_dot_cub(argv[1]))
		error_exit(DOT_CUB);
	if (!check_file_exists(argv[1]))
		error_exit(FAKE_FILE);
	check_elements(argv[1]);
	print_parse_infos();
	return (true);
}
