/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 13:02:52 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 13:03:00 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mouse_motion : Deal with the mouse deplacement for the julia constant
** ----------------------------------------------------------------------------
** expose_hook : Deal with the zoom for the complex fractal
*/

#include "fract_ol.h"

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->c && ((x <= e->xk - 20 || x >= e->xk + 20)
		|| (y <= e->yk - 20 || y >= e->yk + 20)))
	{
		e->yk = y;
		e->xk = x;
		e->zc.x = ft_width(x, e);
		e->zc.i = ft_hight(y, e);
		ft_call_fract(e);
	}
	return (0);
}

int		mouse_zoom(int key, int x, int y, t_env *e)
{
	e->x = x;
	e->y = y;
	if (e->z)
	{
		if (key == 5)
		{
			e->xo = ft_width(x, e);
			e->yo = ft_hight(y, e);
			e->zoom /= 1.5;
		}
		else if (key == 7)
		{
			e->zoom *= 1.5;
		}
		if (key == 5 || key == 7)
			ft_call_fract(e);
	}
	return (0);
}
