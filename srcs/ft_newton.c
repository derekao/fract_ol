/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 13:56:42 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 13:56:56 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_newton_algo : First newton fractal z3-z
** ----------------------------------------------------------------------------
** init : Init
** ----------------------------------------------------------------------------
** ft_newton_algo_2 : Other Newton fractal 8z8 + 16z4 - 12
** ----------------------------------------------------------------------------
** ft_build_newton : Call algo for every point of the plan
** ----------------------------------------------------------------------------
** ft_call_newton : Call the mlx function to trace the newton fractal
*/

#include "fract_ol.h"

static void	ft_newton_algo(t_complex z, t_env *e)
{
	int			color;
	t_complex	zc;
	t_complex	z1;
	t_complex	z2;
	t_complex	z3;

	z1.x = ft_width(z.x, e);
	z1.i = ft_hight(z.i, e);
	zc.x = 2.0;
	zc.i = 0.0;
	color = 0;
	while (ft_mod_complex(z1) < 4.0)
	{
		z2 = ft_power_complex(z1, 3);
		z2 = ft_product_complex(zc, ft_power_complex(z1, 3));
		zc.x = 1.0;
		z2 = ft_sum_complex(z2, zc);
		zc.x = 3.0;
		z3 = ft_product_complex(zc, ft_power_complex(z1, 2));
		z1 = ft_div_complex(z2, z3);
		color++;
		if (color > e->fast)
			break ;
	}
	ft_pixel_put_image(e, z.x, z.i, color * e->color);
}

static void	init(t_complex *z1, t_complex *zc, t_complex z, t_env *e)
{
	z1->x = ft_width(z.x, e);
	z1->i = ft_hight(z.i, e);
	zc->x = 15.0;
	zc->i = 0.0;
}

static void	ft_newton_algo_2(t_complex z, t_env *e)
{
	int			color;
	t_complex	zc;
	t_complex	z1;
	t_complex	z2;
	t_complex	z3;

	init(&z1, &zc, z, e);
	color = 0;
	while (ft_mod_complex(z1) < 30.0)
	{
		z2 = ft_power_complex(z1, 8);
		z3 = ft_product_complex(zc, ft_power_complex(z1, 4));
		zc.x = -16.0;
		z2 = ft_sum_complex(z2, ft_sum_complex(z3, zc));
		zc.x = 8.0;
		z3 = ft_product_complex(zc, ft_power_complex(z1, 7));
		zc.x = 60.0;
		z3 = ft_sum_complex(z3,
			ft_product_complex(zc, ft_power_complex(z1, 3)));
		z2 = ft_div_complex(z2, z3);
		z1 = ft_sum_complex(z1, z2);
		color++;
	}
	ft_pixel_put_image(e, z.x, z.i, color * e->color);
}

void		ft_build_newton(t_env *e)
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
			if (e->c == 1)
				ft_newton_algo_2(z, e);
			else
				ft_newton_algo(z, e);
			j += 1;
		}
		i += 1;
	}
}

void		ft_call_newton(t_env *e)
{
	int	endian;

	e->color = 201;
	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Newton");
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	ft_build_newton(e);
	mlx_hook(e->win, 6, (1L << 6), mouse_motion, e);
	mlx_mouse_hook(e->win, mouse_zoom, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_color, e);
}
