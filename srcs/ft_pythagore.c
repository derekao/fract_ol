/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythagore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:56:41 by semartin          #+#    #+#             */
/*   Updated: 2016/04/15 11:56:50 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_color : Deal with the color
** ----------------------------------------------------------------------------
** ft_print_square : Print a sqaure knowing his size, angle and position
** ----------------------------------------------------------------------------
** ft_pythagore_algo : Recursiv function that trace the tree
** ----------------------------------------------------------------------------
** ft_build_pythagore : Call the recusiv function
** ----------------------------------------------------------------------------
** ft_call_pythagore : Trace the tree with the mlx needed fucntion
*/

#include "fract_ol.h"

static int	ft_color(double size)
{
	if (size == (WIDTH / 7.0))
		return (0xFFBB00);
	else if (size >= 0.5 * (WIDTH / 7.0))
		return (0xFFFF00);
	else if (size >= 0.25 * (WIDTH / 7.0))
		return (0xCCFF99);
	else if (size >= 0.125 * (WIDTH / 7.0))
		return (0x99FF33);
	else if (size >= 0.0625 * (WIDTH / 7.0))
		return (0x66CC66);
	else if (size >= 0.03125 * (WIDTH / 7.0))
		return (0x009966);
	else
		return (0x006600);
}

static void	ft_print_square(t_env *e, double size, t_complex cdb, double phi)
{
	int		i;
	int		j;
	int		color;
	double	x;
	double	y;

	i = 0;
	color = ft_color(size);
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			x = cdb.x + (cos(phi - M_PI_2) * j) + (cos(phi) * i);
			y = cdb.i - (sin(phi - M_PI_2) * j) - (sin(phi) * i);
			ft_pixel_put_image(e, x, y, color);
			if (size > 10 && i < size - 1 && j < size - 1)
			{
				ft_pixel_put_image(e, x + 1, y, color);
				ft_pixel_put_image(e, x, y + 1, color);
			}
			j++;
		}
		i++;
	}
}

static void	ft_pythagore_algo(t_env *e, double size, t_complex cdb, double phi)
{
	t_complex	cdb_1;
	t_complex	cdb_2;
	double		size_1;

	if (size > 1)
	{
		size_1 = (sqrt(2) / 2) * size;
		cdb_1.x = cdb.x + (cos(phi) * size);
		cdb_1.i = cdb.i - (sin(phi) * size);
		cdb_2.x = cdb_1.x + (cos(phi - M_PI_4) * size_1);
		cdb_2.i = cdb_1.i - (sin(phi - M_PI_4) * size_1);
		ft_pythagore_algo(e, size_1, cdb_1, phi + M_PI_4);
		ft_pythagore_algo(e, size_1, cdb_2, phi - M_PI_4);
		ft_print_square(e, size, cdb, phi);
	}
}

void		ft_build_pythagore(t_env *e)
{
	t_complex cdb;

	cdb.x = (3.0 / 7.0) * WIDTH;
	cdb.i = HIGHT;
	ft_pythagore_algo(e, WIDTH / 7.0, cdb, M_PI_2);
}

void		ft_call_pythagore(t_env *e)
{
	int	endian;

	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Pythagore");
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	ft_build_pythagore(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_escape, e);
}
