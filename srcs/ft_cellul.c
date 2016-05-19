/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cellul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:02:44 by semartin          #+#    #+#             */
/*   Updated: 2016/04/13 16:03:00 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_cellul_algo : Algo to trace any cellul function
** -----------------------------------------------------------------------------
** ft_build_cellul_x : Alloc and build the called cellular automaton
** -----------------------------------------------------------------------------
** ft_call_cellul : If cellul in parameter, make the cellular automaton
*/

#include "fract_ol.h"

void	ft_cellul_algo(t_env *e, unsigned char **tab)
{
	int i;
	int j;
	int color;

	i = 0;
	if (e->color == 0x000000)
		color = 0xFFFFFF;
	else
		color = 0x000000;
	while (i < HIGHT)
	{
		j = WIDTH / 2;
		while (j < WIDTH / 2 + WIDTH)
		{
			if (tab[i][j] == 1)
				ft_pixel_put_image(e, j - (WIDTH / 2), i, e->color);
			else
				ft_pixel_put_image(e, j - (WIDTH / 2), i, color);
			j++;
		}
		i++;
	}
}

void	ft_build_cellul_1(t_env *e)
{
	static unsigned char	**tab = NULL;
	int						i;

	if (tab == NULL)
	{
		tab = malloc(sizeof(*tab) * HIGHT * 2);
		i = 0;
		while (i < HIGHT * 2)
			tab[i++] = malloc(sizeof(**tab) * WIDTH * 2);
		i = 0;
		while (i < WIDTH * 2)
			tab[0][i++] = 0;
		tab[0][WIDTH] = 1;
		ft_cellul_1(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_build_cellul_2(t_env *e)
{
	static unsigned char	**tab = NULL;
	int						i;

	if (tab == NULL)
	{
		tab = malloc(sizeof(*tab) * HIGHT * 2);
		i = 0;
		while (i < HIGHT * 2)
			tab[i++] = malloc(sizeof(**tab) * WIDTH * 2);
		i = 0;
		while (i < WIDTH * 2)
			tab[0][i++] = 0;
		tab[0][WIDTH] = 1;
		ft_cellul_2(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_build_cellul_3(t_env *e)
{
	static unsigned char	**tab = NULL;
	int						i;

	if (tab == NULL)
	{
		tab = malloc(sizeof(*tab) * HIGHT * 2);
		i = 0;
		while (i < HIGHT * 2)
			tab[i++] = malloc(sizeof(**tab) * WIDTH * 2);
		i = 0;
		while (i < WIDTH * 2)
			tab[0][i++] = 0;
		tab[0][WIDTH] = 1;
		ft_cellul_3(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_call_cellul(t_env *e)
{
	int	endian;

	e->color = 0x000000;
	e->win = mlx_new_window(e->mlx, WIDTH, HIGHT, "Cellul");
	endian = 1;
	e->img = mlx_new_image(e->mlx, WIDTH, HIGHT);
	e->data = malloc(sizeof(char*));
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &endian);
	ft_build_cellul_1(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_change, e);
}
