/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:06:38 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:01:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_coor *coord, t_fdf *data)
{
	float	delta_x;
	float	delta_y;
	int		max;

	coord->z = data->map[(int)coord->y][(int)coord->x];
	coord->z_ = data->map[(int)coord->y_][(int)coord->x_];
	apply_zoom(coord, data);
	if (coord->z_)
		data->config->color = RED;
	else if (!coord->z && !coord->z_)
		data->config->color = WHITE;
	apply_angle(coord, data);
	delta_x = coord->x_ - coord->x;
	delta_y = coord->y_ - coord->y;
	max = ft_max(ft_abs(delta_x), ft_abs(delta_y));
	delta_x /= max;
	delta_y /= max;
	while ((int)(coord->x - coord->x_) || (int)(coord->y - coord->y_))
	{
		mlx_pixel_put(data->mlx, data->win, coord->x, coord->y, \
			data->config->color);
		coord->x += delta_x;
		coord->y += delta_y;
	}
}

void	draw_map_width(t_fdf *data, int height, t_coor *coord)
{
	int	width;

	width = 0;
	while (width < data->config->width)
	{
		coord->x = width;
		if (width < data->config->width - 1)
		{
			coord->x_ = width + 1;
			coord->y_ = height;
			draw_line(coord, data);
			coord->x = width;
		}
		coord->y = height;
		if (height < data->config->height - 1)
		{
			coord->x_ = width;
			coord->y_ = height + 1;
			draw_line(coord, data);
		}
		coord->y = height;
		width++;
	}
}

void	draw_map_height(t_fdf *data)
{	
	t_coor	*coord;

	coord = malloc(sizeof(*coord));
	if (!coord)
		close_program(data, "Allocation Error\n");
	coord->y = 0;
	while (coord->y < data->config->height)
	{
		draw_map_width(data, coord->y, coord);
		coord->y++;
	}
	free(coord);
	coord = NULL;
}
