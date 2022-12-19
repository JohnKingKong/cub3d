/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:38:01 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 15:24:53 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

float	player_position(char c)
{
	if (c == 'S')
		return (QUART_PI);
	if (c == 'N')
		return (QUART3_PI);
	if (c == 'W')
		return (PI);
	if (c == 'E')
		return (TWO_PI);
	return (0);
}
