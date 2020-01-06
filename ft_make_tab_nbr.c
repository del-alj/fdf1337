/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tab_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:20:16 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/01 04:16:18 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_data	*ft_make_tab_nbr(int len, char *str, int len_x)
{
	int		i;
	int		x;
	t_data	*tab;

	i = -1;
	x = -1;
	tab = (t_data*)malloc(sizeof(t_data) * len_x);
	while (str && ++i < len && str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			x++;
			tab[x].z = atoi(str + i);
			tab[x].colors = 0;
		}
		while (str && i < len && str[i] != '\0' && str[i] != ' ')
		{
			if (str[i] == ',' && i++)
				tab[x].colors = ft_atohex(str + i + 2);
			i++;
		}
	}
	if (x < len_x - 1)
		ft_error_function();
	return (tab);
}
