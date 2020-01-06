/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:23:00 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/01 04:53:19 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_data	**ft_split_nbrs(t_read *bord)
{
	int		j;
	int		i;
	int		len;
	t_data	**tab;

	j = 0;
	tab = (t_data**)malloc(sizeof(t_data*) * bord->nbr_of_y);
	while (bord->line->line && j < bord->nbr_of_y && bord->line->line[j])
	{
		len = (int)ft_strlen(bord->line->line);
		tab[j] = ft_make_tab_nbr(len, bord->line->line, bord->nbr_of_x);
		bord->line = bord->line->next;
		i = 0;
		while (i < bord->nbr_of_x)
			i++;
		j++;
	}
	return (tab);
}
