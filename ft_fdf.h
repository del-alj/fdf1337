/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-alj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:21:35 by del-alj           #+#    #+#             */
/*   Updated: 2020/01/04 01:14:30 by del-alj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <mlx.h>
# include <math.h>
# define W_LENGTH 1500
# define W_WIDTH 2600

typedef struct		s_data_line
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				z1;
	int				z2;
	int				colors;
}					t_data_line;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_data
{
	int				z;
	int				colors;
}					t_data;

typedef struct		s_cal
{
	double			dx;
	double			dy;
	double			x;
	double			y;
	double			p;
}					t_cal;

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_read
{
	int				nbr_of_x;
	int				nbr_of_y;
	int				len_line;
	int				diametre;
	double			angle;
	double			depar_x;
	double			depar_y;
	t_line			*line;
	int				theme;
}					t_read;

typedef struct		s_retation
{
	double			x;
	double			y;
	double			z;
}					t_retation;

typedef struct		s_repit
{
	t_mlx			m;
	t_data			**tab;
	t_read			*bord;
	t_retation		retation;
}					t_repit;

void				ft_print_line(t_data_line cord, t_mlx m,
					int colors, int theme);
t_read				*ft_stock_file(int fd);
int					ft_cont_nbr(char *str);
void				ft_error_function(void);
int					ft_check_nbr(char *str, int i);
t_data				*ft_make_tab_nbr(int len, char *str, int len_x);
t_data				**ft_split_nbrs(t_read *bord);
void				ft_make_window(t_read *bord, t_data **tab);
void				ft_draw_horizontal(t_read *bord, t_data **tab,
					t_mlx m, t_retation *retation);
void				ft_draw_vertical(t_read *bord, t_data **tab, t_mlx m,
					t_retation *retation);
int					ft_atohex(char *str);
void				ft_write_window(t_mlx m);
int					ft_key(int key, t_repit *repit);
void				ft_key_exit(int key, t_repit *repit);

#endif
