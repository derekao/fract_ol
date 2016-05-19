/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:42:42 by semartin          #+#    #+#             */
/*   Updated: 2016/04/13 15:42:57 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_mandelbrot_algo : Algo to trace the mandelbrot Fractal
** -----------------------------------------------------------------------------
** ft_build_mandelbrot : Call the mandelbrot algo for each point of the plan
** -----------------------------------------------------------------------------
** ft_call_mandelbrot : Call mandelbrot if asked
** -----------------------------------------------------------------------------
** ft_build_ikeda : Build ikeda
** -----------------------------------------------------------------------------
** ft_call_ikeda : Call ikeda if asked
*/

#include "fract_ol.h"

static void	ft_mandelbrot_algo(t_complex z, t_env *e)
{
	int			color;
	t_complex	zc;
	t_complex	z1;
	t_complex	z2;

	z1.x = ft_width(z.x, e);
	z1.i = ft_hight(z.i, e);
	zc.x = z1.x;
	zc.i = z1.i;
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

void		ft_build_mandelbrot(t_env *e)
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
			ft_mandelbrot_algo(z, e);
			j += 1;
		}
		i += 1;
	}
}

void		ft_call_mandelbrot(t_env *e)
{
	int	endian;

	e->color = 1;
	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Mandelbrot");
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	mlx_mouse_hook(e->win, mouse_zoom, e);
	ft_build_mandelbrot(e);
	mlx_mouse_hook(e->win, mouse_zoom, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_color, e);
}

void		ft_build_ikeda(t_env *e)
{
	int		i;
	double	*x;
	double	y;
	double	y1;
	double	r;

	i = 0;
	y = 0;
	x = malloc(sizeof(*x) * 2);
	x[0] = 0;
	while (i < 1000000)
	{
		r = 0.4 - (6 / (1 + (x[0] * x[0]) + (y * y)));
		x[1] = 1 + 0.9 * ((x[0] * cos(r)) - (y * sin(r)));
		y1 = 0.9 * ((x[0] * sin(r)) + (y * cos(r)));
		x[0] = x[1];
		y = y1;
		ft_pixel_put_image(e, x[0] * WIDTH / 4 + (WIDTH / 4),
							y * HIGHT / 4 + (HIGHT / 1.5), 0xFFFFFF);
		i++;
	}
	free(x);
}

void		ft_call_ikeda(t_env *e)
{
	int	endian;

	e->xo = 0;
	e->zoom = 1.0;
	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Ikeda");
	mlx_clear_window(e->mlx, e->win);
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	ft_build_ikeda(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_escape, e);
}
