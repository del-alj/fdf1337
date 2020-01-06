/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:36:08 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/01 03:59:22 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_atohex(char *str)
{
	int	i;
	int	val;
	int	hex;

	hex = 0;
	i = 0;
	val = 0;
	while (i < 6 && str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			val = str[i] - 97 + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			val = str[i] - 65 + 10;
		hex = hex << 4 | val;
		i++;
	}
	return (hex);
}
