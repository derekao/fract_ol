/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 12:50:34 by semartin          #+#    #+#             */
/*   Updated: 2015/09/17 13:18:04 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

/*
** ft_pixel_put_image : Put a pixel of the color on the image
*/

void	ft_pixel_put_image(t_env *e, int x, int y, int color)
{
	unsigned int pos;
	unsigned int mem;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HIGHT)
	{
		pos = (y * e->size_line) + ((e->bpp / 8) * x);
		mem = mlx_get_color_value(e->mlx, color);
		e->data[pos + 0] = (mem & 0xFF);
		e->data[pos + 1] = (mem & 0xFF00) >> 8;
		e->data[pos + 2] = (mem & 0xFF0000) >> 16;
	}
}
