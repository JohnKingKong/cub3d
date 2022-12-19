/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:06:21 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 16:01:06 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data	*cardinal_points(t_ray *ray, t_mlx *game)
{
	if (ray->hit_down && ray->hit_left)
		return (&game->texture.north);
	else if (ray->hit_left && !ray->hit_down)
		return (&game->texture.west);
	else if (!ray->hit_left && ray->hit_down)
		return (&game->texture.east);
	else if (!ray->hit_down && !ray->hit_left)
		return (&game->texture.south);
	return (NULL);
}

static void	draw_f_c(t_mlx *game, int x, int i)
{
	t_map_infos	*info;

	info = get_infos();
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(&game->img, x, i,
			create_rgb(ft_atoi(info->color[0][0]),
				ft_atoi(info->color[0][1]), ft_atoi(info->color[0][2])));
		my_mlx_pixel_put(&game->img, x, HEIGHT - i,
			create_rgb(ft_atoi(info->color[1][0]),
				ft_atoi(info->color[1][1]), ft_atoi(info->color[1][2])));
		i++;
	}
}

static void	step_x(t_ray *ray, t_three *three, t_data *img)
{
	if ((ray->hit_down && ray->hit_left) || (!ray->hit_down && !ray->hit_left))
		three->step_x = fmod(ray->delta_x, WIDTH_ASSET);
	else
		three->step_x = fmod(ray->delta_y, WIDTH_ASSET);
	three->step_x = three->step_x * (img->img_width / WIDTH_ASSET);
}

static void	print_wall_texture(t_data *img, int x, t_mlx *game, t_three *three)
{
	int	i;
	int	color;

	i = 0;
	while (i < three->line_h)
	{
		color = get_pixel(img, three->step_x, three->step_y);
		my_mlx_pixel_put(&game->img, x, i + three->line_o, color);
		three->step_y += three->ty_step;
		i++;
	}
	draw_f_c(game, x, i + three->line_o);
}

void	print_texture(t_mlx *game, t_three *three, int x)
{
	t_data	*img;

	img = cardinal_points(&game->ray[x], game);
	three->line_h = ((WIDTH_ASSET * HEIGHT) / game->ray[x].dist);
	three->ty_step = img->img_height / three->line_h;
	if (img->img_height > HEIGHT)
		three->ty_step *= HEIGHT / img->img_height;
	if (three->line_h > HEIGHT)
	{
		three->ty_off = (three->line_h - HEIGHT) / 2.0;
		three->line_h = HEIGHT;
	}
	three->line_o = ((HEIGHT / 2.0) - three->line_h / 2.0);
	three->step_y = three->ty_off * three->ty_step;
	step_x(&game->ray[x], three, img);
	if ((game->ray[x].hit_down && game->ray[x].hit_left)
		|| (game->ray[x].hit_left && !game->ray[x].hit_down))
		three->step_x = img->img_width - three->step_x;
	print_wall_texture(img, x, game, three);
}
