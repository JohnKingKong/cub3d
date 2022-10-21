/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:09:39 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/21 13:59:27 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

float normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

int get_pixel(t_data *data, int x, int y)
{
	if (x >= data->img_width || x < 0 || y >= data->img_height || y < 0)
		return 0;
	char *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return *(unsigned int *)dst;
}
