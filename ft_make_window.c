/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:58 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/03 20:41:40 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_diametre(t_read *bord)
{
	int			diametre;

	diametre = sqrt(pow(((bord->nbr_of_y + 1) * bord->len_line), 2)
			+ pow(((bord->nbr_of_x + 1) * bord->len_line), 2));
	return (diametre);
}

void	ft_free(t_line *bord)
{
	t_line *bord1;

	while (bord)
	{
		bord1 = bord;
		bord = bord->next;
		free(bord1);
		bord1 = NULL;
	}
}

void	ft_make_window(t_read *bord, t_data **tab)
{
	t_mlx		m;
	t_retation	retation;
	t_repit		repit;

	m.mlx_ptr = mlx_init();
	bord->diametre = sqrt(pow(((bord->nbr_of_y + 1) * bord->len_line), 2)
			+ pow(((bord->nbr_of_x + 1) * bord->len_line), 2));
	m.win_ptr = mlx_new_window(m.mlx_ptr, W_WIDTH, W_LENGTH, "FDF");
	while ((W_LENGTH - 200) <= bord->diametre && bord->len_line--)
		bord->diametre = sqrt(pow(((bord->nbr_of_y + 1) * bord->len_line), 2)
				+ pow(((bord->nbr_of_x + 1) * bord->len_line), 2));
	bord->angle = 0;
	bord->depar_x = (bord->angle == 0) ? ((W_WIDTH - ((bord->nbr_of_x + 1)
					* bord->len_line)) / 2) : (W_WIDTH / 2);
	bord->depar_y = (W_LENGTH - ((bord->nbr_of_y) * bord->len_line)) / 2;
	bord->theme = 0;
	ft_draw_vertical(bord, tab, m, &retation);
	ft_draw_horizontal(bord, tab, m, &retation);
	ft_write_window(m);
	repit.m = m;
	repit.tab = tab;
	repit.bord = bord;
	repit.retation = retation;
	mlx_hook(m.win_ptr, 2, 0, ft_key, &repit);
	mlx_loop(m.mlx_ptr);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_read		*bord;
	t_data		**tab;
	char		*str;

	if (argc != 2)
		ft_putendl("usage : [program name] [input file]");
	else
	{
		fd = open(argv[1], O_RDONLY);
		bord = ft_stock_file(fd);
		close(fd);
		bord->nbr_of_x = ft_cont_nbr(bord->line->line);
		tab = ft_split_nbrs(bord);
		ft_free(bord->line);
		ft_make_window(bord, tab);
	}
	return (0);
}
