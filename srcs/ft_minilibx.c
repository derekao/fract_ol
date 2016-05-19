/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:28:18 by semartin          #+#    #+#             */
/*   Updated: 2015/11/02 10:04:16 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
** ft_call_fract : Trace the called fractal and ask people to wait
** ----------------------------------------------------------------------------
** expose_hook : Deal with the expose
** ----------------------------------------------------------------------------
** ft_initialise : Initialise param
** ----------------------------------------------------------------------------
** ft_minilibx : Call any minilibx related function
*/

void		ft_call_fract(t_env *e)
{
	ft_putendl("..........Wait..........");
	if (e->all->julia == 1)
		ft_build_julia(e);
	else if (e->all->mandelbrot == 1)
		ft_build_mandelbrot(e);
	else if (e->all->ikeda == 1)
		ft_build_ikeda(e);
	else if (e->all->newton == 1)
		ft_build_newton(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_putendl("Continue");
}

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static void	ft_initialise(t_env *e)
{
	e->zc.x = -0.772691322542185;
	e->zc.i = 0.124281466072787;
	e->zoom = 2.0;
	e->mlx = mlx_init();
	e->x = WIDTH / 2;
	e->y = HIGHT / 2;
	e->yk = -50;
	e->xk = -50;
	e->z = 0;
	e->c = 0;
	e->xo = 0;
	e->yo = 0;
	e->fast = 256;
}

void		ft_minilibx(t_fract *all)
{
	t_env *e;

	e = malloc(sizeof(*e));
	ft_initialise(e);
	e->all = all;
	if (all->julia == 1)
		ft_call_julia(e);
	if (all->mandelbrot == 1)
		ft_call_mandelbrot(e);
	if (all->cellul == 1)
		ft_call_cellul(e);
	if (all->ikeda == 1)
		ft_call_ikeda(e);
	if (all->pythagore == 1)
		ft_call_pythagore(e);
	if (all->newton == 1)
		ft_call_newton(e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	free(e);
}
