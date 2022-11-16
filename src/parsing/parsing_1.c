/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:33:17 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/31 16:04:45 by jvigneau         ###   ########.fr       */
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

bool	start_parse(char *argv[], int argc)
{
	if (argc != 2)
		error_exit(ARGC);
	if (!check_dot_cub(argv[1]))
		error_exit(DOT_CUB);
	if (!check_file_exists(argv[1]))
		error_exit(FAKE_FILE);
	check_elements(argv[1]);
	free_parsing();
	return (true);
}
