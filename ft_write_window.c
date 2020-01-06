/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:31:33 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/03 21:56:26 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_write_window(t_mlx m)
{
	int		cl;

	cl = 0x19CF35;
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 960, cl, "Type Of Projection :");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 70, 1000, cl, "Parallel   : p");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 70, 1030, cl, "Isometrics : i");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1140, cl, "To Move :");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 200, 1130, cl, "^");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 180, 1140, cl, "<   >");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 200, 1150, cl, "v");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1200, cl, "To Rotat x : x s");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1230, cl, "To Rotat y : y u");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1260, cl, "To Rotat z : z a");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1330, cl, "To Zoom [+]:   +");
	mlx_string_put(m.mlx_ptr, m.win_ptr, 50, 1360, cl, "To Zoom [-]:   -");
}
