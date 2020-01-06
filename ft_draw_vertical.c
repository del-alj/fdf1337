/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:52:52 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/03 23:39:48 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw_v_help(t_read *bord, t_data_line *c,
		t_retation *retation, t_mlx m)
{
	if (bord->angle != 0)
	{
		c->y1 = (c->y1 * sin(retation->x)) - (c->z1 * cos(retation->x));
		c->y2 = (c->y2 * sin(retation->x)) - (c->z2 * cos(retation->x));
		c->x1 = (c->x1 * cos(retation->y)) - (c->z1 * sin(retation->y));
		c->x2 = (c->x2 * cos(retation->y)) - (c->z2 * sin(retation->y));
	}
	c->x1 = (c->x1 * bord->len_line) + bord->depar_x;
	c->x2 = (c->x2 * bord->len_line) + bord->depar_x;
	c->y1 = (c->y1 * bord->len_line) + bord->depar_y;
	c->y2 = (c->y2 * bord->len_line) + bord->depar_y;
}

void	ft_draw_vertical(t_read *bord, t_data **tab, t_mlx m,
		t_retation *retation)
{
	int			colors;
	int			i;
	int			j;
	t_data_line	c;

	i = -1;
	while (++i <= bord->nbr_of_x && (j = -1))
	{
		while (++j < bord->nbr_of_y)
		{
			c.z2 = (i < bord->nbr_of_x && (j + 1 < bord->nbr_of_y)) ?
				tab[j + 1][i].z : 0;
			c.z1 = (i < bord->nbr_of_x) ? tab[j][i].z : 0;
			c.colors = (i < bord->nbr_of_x && tab[j][i].colors != 0) ?
				tab[j][i].colors : 0xffffff;
			c.x1 = (i * cos(retation->z)) - (j * sin(retation->z));
			c.x2 = (i * cos(retation->z)) - ((j + 1) * sin(retation->z));
			c.y1 = (i * sin(retation->z)) + (j * cos(retation->z));
			c.y2 = (i * sin(retation->z) + ((j + 1) * cos(retation->z)));
			ft_draw_v_help(bord, &c, retation, m);
			if ((c.x1 > 0 && c.y1 > 0 && c.x1 < W_WIDTH && c.y1 < W_LENGTH)
				|| (c.x2 > 0 && c.y2 > 0 && c.x2 < W_WIDTH && c.y2 < W_LENGTH))
				ft_print_line(c, m, c.colors, bord->theme);
		}
	}
}
