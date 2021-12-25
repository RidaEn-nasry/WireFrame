/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:47:19 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:02:14 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_width(t_fdf *data, char *err_msg)
{
	if (!data->config->width)
	{
		free(data);
		free(data->config);
		ft_error(err_msg);
	}
}

void	check_map(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
	}
}

void	close_program(t_fdf *data, char *err_msg)
{
	int	i;

	i = 0;
	check_width(data, err_msg);
	check_map(data);
	if (data->mlx)
	{
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		free(data->win);
		data->win = NULL;
	}
	free(data);
	data = NULL;
	ft_putstr_fd(err_msg, 1);
	exit(0);
}
