/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:33:17 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/25 13:07:15 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_dot_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!ft_strnstr(filename, ".cub", len) || filename[len -4] != '.')
		return (false);
	else if (filename[len - 5] == '/')
		error_exit("just_cub");
	return (true);
}

static bool	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	start_parse(char *argv[], int argc) 
{
	if (argc != 2)
		error_exit("argc");
	if (!check_dot_cub(argv[1]))
		error_exit("extension");
	if (!check_file_exists(argv[1]))
		error_exit("fake_file");
	check_elements(argv[1]);
	return (true);
}