/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:50:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:02:03 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	apply_zoom(t_coor *coord, t_fdf *data)
{
	coord->x *= data->config->zoom;
	coord->y *= data->config->zoom;
	coord->x_ *= data->config->zoom;
	coord->y_ *= data->config->zoom;
}

void	apply_angle(t_coor *coord, t_fdf *data)
{
	coord->x = (coord->x - coord->y) * cos(1.085);
		coord->y = (coord->x + coord->y) * sin(1.085) - \
	(data->config->altitude * coord->z);
	coord->x += data->config->shift_x;
	coord->y += data->config->shift_y;
	coord->x_ = (coord->x_ - coord->y_) * cos(1.085);
	coord->y_ = (coord->x_ + coord->y_) * sin(1.085) - \
		(data->config->altitude * coord->z_);
	coord->x_ += data->config->shift_x;
	coord->y_ += data->config->shift_y;
}
