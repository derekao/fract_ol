/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cellul_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:10:47 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 16:10:59 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_build_cellul_x : Alloc and build the called cellular automaton
** -----------------------------------------------------------------------------
** ft_cellul_x : Fill the tab for the cellular automaton with the right cond
*/

#include "fract_ol.h"

void	ft_build_cellul_4(t_env *e)
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
		ft_cellul_4(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_build_cellul_5(t_env *e)
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
		ft_cellul_5(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_build_cellul_6(t_env *e)
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
		ft_cellul_6(tab);
	}
	ft_cellul_algo(e, tab);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_cellul_6(unsigned char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < HIGHT * 2)
	{
		j = -1;
		while (++j < WIDTH * 2)
		{
			if (j == 0 || j == (WIDTH * 2) - 1)
				tab[i][j] = 0;
			else if ((tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 1)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0)
				|| (tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 0)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 1))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
		}
		i++;
	}
}
