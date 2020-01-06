/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:31:59 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/03 21:32:05 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_free_tab(t_repit *repit)
{
	int	i;

	i = 0;
	while (i < repit->bord->nbr_of_y)
	{
		free(repit->tab[i]);
		i++;
	}
	free(repit->tab);
	free(repit->bord);
}

void	ft_key_exit(int key, t_repit *repit)
{
	if (key == 53)
	{
		ft_free_tab(repit);
		exit(0);
	}
}
