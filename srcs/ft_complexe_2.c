/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:40:23 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 16:40:24 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_x_complex : Make the operation called with Complexe numbers
*/

#include "fract_ol.h"

t_complex	ft_power_complex(t_complex z, int nb)
{
	int			i;
	t_complex	z1;

	i = 1;
	if (nb == 0)
	{
		z1.x = 1;
		z1.i = 0;
	}
	z1 = z;
	while (i < nb)
	{
		z1 = ft_product_complex(z, z1);
		i++;
	}
	return (z1);
}
