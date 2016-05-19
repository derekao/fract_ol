/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complexe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:54:32 by semartin          #+#    #+#             */
/*   Updated: 2016/04/12 12:54:50 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_x_complex : Make the operation called with Complexe numbers
*/

#include "fract_ol.h"

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex z;

	z.x = z1.x + z2.x;
	z.i = z1.i + z2.i;
	return (z);
}

t_complex	ft_diff_complex(t_complex z1, t_complex z2)
{
	t_complex z;

	z.x = z1.x - z2.x;
	z.i = z1.i - z2.i;
	return (z);
}

t_complex	ft_product_complex(t_complex z1, t_complex z2)
{
	t_complex z;

	z.x = (z1.x * z2.x) - (z1.i * z2.i);
	z.i = (z1.x * z2.i) + (z2.x * z1.i);
	return (z);
}

t_complex	ft_div_complex(t_complex z1, t_complex z2)
{
	t_complex	z;
	double		x;

	x = (z2.x * z2.x) + (z2.i * z2.i);
	z.x = ((z1.x * z2.x) + (z1.i * z2.i)) / x;
	z.i = ((z2.x * z1.i) - (z1.x * z2.i)) / x;
	return (z);
}

double		ft_mod_complex(t_complex z)
{
	return (sqrt((z.x * z.x) + (z.i * z.i)));
}
