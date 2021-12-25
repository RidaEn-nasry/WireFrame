/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:52:56 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:02:17 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == LEFT)
		data->config->shift_x -= 10;
	else if (key == RIGHT)
		data->config->shift_x += 10;
	else if (key == DOWN)
		data->config->shift_y += 10;
	else if (key == UP)
		data->config->shift_y -= 10;
	else if (key == ZOOM_IN)
		data->config->zoom += 2;
	else if (key == ZOOM_OUT)
		data->config->zoom -= 2;
	else if (key == ALTITUDE_UP)
		data->config->altitude += 0.1;
	else if (key == ALTITUDE_DOWN)
		data->config->altitude -= 0.1;
	else if (key == EXIT)
		close_program(data, "Exit program.\n");
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	draw_map_height(data);
	return (0);
}

void	init_config(float *altitude, int *zoom, int *shift_x, int *shift_y)
{
	*altitude = ALTITUDE;
	*zoom = ZOOM;
	*shift_x = SHIFT_X;
	*shift_y = SHIFT_Y;
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
		ft_error("Error : invalid number of arguments.\n");
	data = malloc(sizeof(*data));
	data->config = malloc(sizeof(*data->config));
	if (!data || !data->config)
		return (0);
	get_data(av[1], data);
	if (!data->map)
		close_program(data, "Error.\n");
	data->mlx = mlx_init();
	if (!data->mlx)
		close_program(data, "Mlx error.\n");
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	if (!data->win)
		close_program(data, "Mlx error.\n");
	init_config(&data->config->altitude, &data->config->zoom, \
	&data->config->shift_x, &data->config->shift_y);
	draw_map_height(data);
	mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	return (0);
}
