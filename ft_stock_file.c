/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:45:37 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/01 04:54:44 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_read	*ft_stock_file(int fd)
{
	t_read	*bord;
	t_line	*node;

	bord = (t_read*)malloc(sizeof(t_read));
	bord->nbr_of_y = 0;
	bord->nbr_of_x = 0;
	bord->len_line = 20;
	node = (t_line*)malloc(sizeof(t_line));
	bord->line = node;
	while (get_next_line(fd, &node->line) > 0)
	{
		node->next = (t_line*)malloc(sizeof(t_line));
		node = node->next;
		bord->nbr_of_y++;
	}
	if (bord->nbr_of_y <= 0)
		ft_error_function();
	node->next = NULL;
	return (bord);
}
