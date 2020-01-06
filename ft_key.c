/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:35:18 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/05 02:43:27 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_key_move(int key, t_repit *repit)
{
	if (key == 123)
		(repit->bord)->depar_x = (repit->bord)->depar_x - 10;
	else if (key == 124)
		(repit->bord)->depar_x = (repit->bord)->depar_x + 10;
	if (key == 125)
		(repit->bord)->depar_y = (repit->bord)->depar_y + 10;
	else if (key == 126)
		(repit->bord)->depar_y = (repit->bord)->depar_y - 10;
}

void	ft_key_mode(int key, t_repit *repit)
{
	if (key == 35)
	{
		repit->bord->angle = 0;
		repit->retation.z = 0;
		repit->retation.x = 0;
		repit->retation.y = 0;
	}
	if (key == 34)
	{
		repit->bord->angle = 1;
		repit->retation.z = (M_PI / 6);
		repit->retation.x = (M_PI / 6);
		repit->retation.y = 0;
	}
}

void	ft_key_rotat(int key, t_repit *repit)
{
	if (key == 6)
		repit->retation.z = repit->retation.z - 0.05;
	if (key == 0)
		repit->retation.z = repit->retation.z + 0.05;
	if (key == 7)
		repit->retation.x = repit->retation.x + 0.03;
	if (key == 1)
		repit->retation.x = repit->retation.x - 0.03;
	if (key == 16)
		repit->retation.y = repit->retation.y + 0.03;
	if (key == 32)
		repit->retation.y = repit->retation.y - 0.03;
}

void	ft_key_zoom(int key, t_repit *repit)
{
	if (key == 69)
	{
		repit->bord->len_line = repit->bord->len_line + 5;
		repit->bord->depar_x -= repit->bord->nbr_of_x;
		repit->bord->depar_y -= repit->bord->nbr_of_y;
	}
	if (repit->bord->len_line > 1 && key == 78)
	{
		repit->bord->len_line = repit->bord->len_line - 5;
		repit->bord->depar_x += repit->bord->nbr_of_x;
		repit->bord->depar_y += repit->bord->nbr_of_y;
	}
	if (key == 8 && repit->bord->theme == 0)
		repit->bord->theme = 1;
	else if (key == 8 && repit->bord->theme == 1)
		repit->bord->theme = 0;
}

int		ft_key(int key, t_repit *repit)
{
	if (key >= 123 && key <= 126)
		ft_key_move(key, repit);
	if (key == 35 || key == 34)
		ft_key_mode(key, repit);
	ft_key_rotat(key, repit);
	if (key == 69 || key == 78 || key == 8)
		ft_key_zoom(key, repit);
	ft_key_exit(key, repit);
	mlx_clear_window(repit->m.mlx_ptr, repit->m.win_ptr);
	ft_draw_vertical(repit->bord, repit->tab, repit->m, &repit->retation);
	ft_draw_horizontal(repit->bord, repit->tab, repit->m, &repit->retation);
	ft_write_window(repit->m);
	return (0);
}
