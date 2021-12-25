/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:57:35 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:02:20 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_words(char *s)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == ' ' && flag == 1)
			flag = 0;
		if (s[i] != ' ' && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

void	get_dimentions(char *path, t_fdf *data)
{	
	int		fd;
	int		height;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 1 || read(fd, NULL, 0) < 0)
		ft_error("Map error : invalid path.\n");
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		data->config->width = 0;
		close_program(data, "Map error : empty file.\n");
	}
	data->config->width = count_words(line);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->config->height = height;
}

void	fill_map(char *path, t_fdf *data)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**nums;

	fd = open(path, O_RDONLY);
	i = 0;
	while (i < data->config->height)
	{
		j = 0;
		line = get_next_line(fd);
		nums = ft_split(line, ' ');
		while (j < data->config->width)
		{
			data->map[i][j] = ft_atoi(nums[j]);
			j++;
		}
		free(line);
		nums = ft_free_tab(nums);
		i++;
	}
	close(fd);
}

void	get_data(char *path, t_fdf *data)
{
	int	i;

	get_dimentions(path, data);
	data->map = malloc(sizeof(int *) * (data->config->height));
	if (!data->map)
		return ;
	i = 0;
	while (i < data->config->height)
	{
		data->map[i] = malloc(sizeof(int) * (data->config->width));
		if (!data->map[i])
		{
			while (i > 0)
			{
				free(data->map[i]);
				i--;
			}
			free(data->map);
			data->map = NULL;
			return ;
		}
		i++;
	}
	data->map[i] = NULL;
	fill_map(path, data);
}
