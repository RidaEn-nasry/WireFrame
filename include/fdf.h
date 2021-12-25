/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:51:36 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/12/25 19:01:08 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "./libft.h"

//KeyCodes
# define LEFT 123
# define RIGHT 124
# define UP 126 
# define DOWN 125
# define ZOOM_IN 6
# define ZOOM_OUT 0
# define ALTITUDE_UP 4
# define ALTITUDE_DOWN 2
# define EXIT 53

//Config Macros
# define ZOOM 30
# define ALTITUDE 2.5
# define SHIFT_X 950
# define SHIFT_Y 200

//Colors
# define RED 0xff0000
# define WHITE 0xffffff

typedef struct s_config {
	int		height;
	int		width;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	altitude;
}	t_config;

typedef struct s_fdf
{
	int			**map;
	void		*mlx;
	void		*win;
	t_config	*config;
}	t_fdf;

typedef struct s_coor
{
	float	x;
	float	y;
	float	x_;
	float	y_;
	int		z;
	int		z_;
}	t_coor;

void	get_data(char *path, t_fdf *data);
void	close_program(t_fdf *data, char *s);
float	ft_abs(float x);
float	ft_max(float a, float b);
void	draw_map_height(t_fdf *data);
void	draw_map_width(t_fdf *data, int height, t_coor *coos);
void	apply_zoom(t_coor *coos, t_fdf *data);
void	apply_angle(t_coor *coos, t_fdf *data);

#endif
