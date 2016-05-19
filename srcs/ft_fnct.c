/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:01:21 by semartin          #+#    #+#             */
/*   Updated: 2016/04/15 14:01:31 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_x : Deal with the zoom
*/

#include "fract_ol.h"

double	ft_width(double i, t_env *e)
{
	double x;

	x = i * (e->zoom / WIDTH) + e->xo - ((WIDTH / 2.0) * (e->zoom / WIDTH));
	return (x);
}

double	ft_hight(double i, t_env *e)
{
	double x;

	x = i * (e->zoom / HIGHT) + e->yo - ((HIGHT / 2.0) * (e->zoom / HIGHT));
	return (x);
}
