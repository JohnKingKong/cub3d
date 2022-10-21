/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:05:51 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/19 01:56:30 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_v ray_dir_init(float angle)
{
	t_v ray_dir;

	ray_dir.x = cos(angle);
	if (!ray_dir.x)
		ray_dir.x = 1e30;
	ray_dir.y = sin(angle);
	if (!ray_dir.y)
		ray_dir.y = 1e30;
	return (ray_dir);
}

t_ray dda_v2(t_mlx *game, float angle)
{
	t_dda dda;
	ft_memset(&dda, 0, sizeof(dda));
	angle = normalize_angle(angle); // a pt remove 
	
	dda.ray_dir = ray_dir_init(angle);		
	
	dda.step_size.x = fabsf(1.f / dda.ray_dir.x);
	dda.step_size.y = fabsf(1.f / dda.ray_dir.y);
	if (dda.ray_dir.x < 0)
	{
		dda.step.x = -1;
		dda.ray_lenght = 
		
	}



	
}