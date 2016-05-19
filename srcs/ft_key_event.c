/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 12:09:14 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 12:09:23 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_precision : Deal with : Precision and zoom with past keybord entrance
** -----------------------------------------------------------------------------
** ft_key_color : Deal with the color on Julia / Mandelbrot / Newton
** -----------------------------------------------------------------------------
** key_color : Analyse any key entrance with Julia / Mandelbrot / Newton
** -----------------------------------------------------------------------------
** key_escape : Leave programe if escape pressed
** -----------------------------------------------------------------------------
** key_change : Deal with every change on the cellular automaton
*/

#include "fract_ol.h"

static int	ft_precision(t_env *e, int keycode)
{
	if (keycode == 45 && e->fast > 64)
		e->fast -= 64;
	else if (keycode == 61)
		e->fast += 64;
	else if (keycode == 122)
		e->z = (e->z == 1) ? 0 : 1;
	else if (keycode == 99)
		e->c = (e->c == 1) ? 0 : 1;
	else if (keycode == 65365)
	{
		e->xo = ft_width(e->x, e);
		e->yo = ft_hight(e->y, e);
		e->zoom /= 1.5;
	}
	else if (keycode == 65366)
		e->zoom *= 1.5;
	else
		return (0);
	return (1);
}

static int	ft_key_color(t_env *e, int keycode)
{
	if (keycode == 65457)
		e->color = 1;
	else if (keycode == 65458)
		e->color = 16;
	else if (keycode == 65459)
		e->color = 256;
	else if (keycode == 65460)
		e->color = 4096;
	else if (keycode == 65461)
		e->color = 65536;
	else if (keycode == 65462)
		e->color = 1048576;
	else if (keycode == 65463)
		e->color = 201;
	else if (keycode == 65464)
		e->color = 256 * 49;
	else if (keycode == 65465)
		e->color = 65536 * 14;
	else
		return (0);
	return (1);
}

int			key_color(int keycode, t_env *e)
{
	int		change;

	change = 0;
	change = ft_precision(e, keycode);
	change += ft_key_color(e, keycode);
	if (change)
		ft_call_fract(e);
	if (keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int			key_escape(int keycode, t_env *e)
{
	while (!e)
		e = NULL;
	if (keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int			key_change(int keycode, t_env *e)
{
	if (keycode == 65457)
		ft_build_cellul_1(e);
	else if (keycode == 65458)
		ft_build_cellul_2(e);
	else if (keycode == 65459)
		ft_build_cellul_3(e);
	else if (keycode == 65460)
		ft_build_cellul_4(e);
	else if (keycode == 65461)
		ft_build_cellul_5(e);
	else if (keycode == 65462)
		ft_build_cellul_6(e);
	else if (keycode == 65451)
	{
		e->color = 0x000000;
		ft_build_cellul_1(e);
	}
	else if (keycode == 65453)
	{
		e->color = 0xFFFFFF;
		ft_build_cellul_1(e);
	}
	if (keycode == 65307)
		exit(0);
	return (0);
}
