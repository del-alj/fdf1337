/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:50:52 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/03 22:54:33 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_swap_cord(t_data_line *cord)
{
	double	x;
	double	y;

	x = cord->x1;
	cord->x1 = cord->x2;
	cord->x2 = x;
	y = cord->y1;
	cord->y1 = cord->y2;
	cord->y2 = y;
}

int		ft_change_color(int theme, int colors, t_data_line cord)
{
	if (theme == 1 && colors == 0xffffff)
	{
		if (cord.z1 != 0 && cord.z2 != 0)
			colors = 0x9e3d64;
		else if (cord.z1 > cord.z2 || cord.z1 < cord.z2)
			colors = 0xffb554;
	}
	return (colors);
}

void	plotlinelow(t_data_line cord, t_mlx m, int colors, int theme)
{
	t_cal	cal;
	int		y;

	cal.dx = cord.x2 - cord.x1;
	cal.dy = cord.y2 - cord.y1;
	y = (cal.dy < 0) ? -1 : 1;
	if (cal.dy < 0)
		cal.dy = -1 * cal.dy;
	cal.p = (2 * cal.dy) - cal.dx;
	while (cord.x1 < cord.x2)
	{
		colors = ft_change_color(theme, colors, cord);
		mlx_pixel_put(m.mlx_ptr, m.win_ptr, cord.x1, cord.y1, colors);
		if (cal.p >= 0)
		{
			cord.y1 = cord.y1 + y;
			cal.p = cal.p + (2 * cal.y) - (2 * cal.dx);
		}
		else
		{
			cal.p = cal.p + (2 * cal.dy);
			cord.x1++;
		}
	}
}

void	plotlinehigh(t_data_line cord, t_mlx m, int colors, int theme)
{
	t_cal	cal;
	int		x;

	cal.dx = cord.x2 - cord.x1;
	cal.dy = cord.y2 - cord.y1;
	x = (cal.dx < 0) ? -1 : 1;
	if (cal.dx < 0)
		cal.dx = -1 * cal.dx;
	cal.p = (2 * cal.dx) - cal.dy;
	while (cord.y1 < cord.y2)
	{
		colors = ft_change_color(theme, colors, cord);
		mlx_pixel_put(m.mlx_ptr, m.win_ptr, cord.x1, cord.y1, colors);
		if (cal.p >= 0)
		{
			cord.x1 = cord.x1 + x;
			cal.p = cal.p - (2 * cal.dy);
		}
		else
		{
			cal.p = cal.p + (2 * cal.dx);
			cord.y1++;
		}
	}
}

void	ft_print_line(t_data_line cord, t_mlx m, int colors, int theme)
{
	double	x;
	double	y;

	if (fabs(cord.y2 - cord.y1) < fabs(cord.x2 - cord.x1))
	{
		if (cord.x1 > cord.x2)
			ft_swap_cord(&cord);
		plotlinelow(cord, m, colors, theme);
	}
	else
	{
		if (cord.y1 > cord.y2)
			ft_swap_cord(&cord);
		plotlinehigh(cord, m, colors, theme);
	}
}
