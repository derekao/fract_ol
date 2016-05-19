/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:35:30 by semartin          #+#    #+#             */
/*   Updated: 2016/04/12 13:35:43 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_julia_algo : Algo to trace the Julia Fractal
** -----------------------------------------------------------------------------
** ft_build_julia : Call the julia algo for each point of the plan
** -----------------------------------------------------------------------------
** ft_call_julia : Call julia if asked
*/

#include "fract_ol.h"

static void	ft_julia_algo(t_complex z, t_env *e)
{
	int			color;
	t_complex	zc;
	t_complex	z1;
	t_complex	z2;

	z1.x = ft_width(z.x, e);
	z1.i = ft_hight(z.i, e);
	zc.x = e->zc.x;
	zc.i = e->zc.i;
	color = 0;
	while (ft_mod_complex(z1) < 2.0)
	{
		z2 = ft_product_complex(z1, z1);
		z1 = ft_sum_complex(z2, zc);
		color++;
		if (color > e->fast)
			break ;
	}
	ft_pixel_put_image(e, z.x, z.i, color * e->color);
}

void		ft_build_julia(t_env *e)
{
	int			i;
	int			j;
	t_complex	z;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HIGHT)
		{
			z.x = i;
			z.i = j;
			ft_julia_algo(z, e);
			j += 1;
		}
		i += 1;
	}
}

void		ft_call_julia(t_env *e)
{
	int	endian;

	e->color = 1;
	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Julia");
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	ft_build_julia(e);
	mlx_hook(e->win, 6, (1L << 6), mouse_motion, e);
	mlx_mouse_hook(e->win, mouse_zoom, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_color, e);
}
