/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cellul_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:55:42 by semartin          #+#    #+#             */
/*   Updated: 2016/04/24 15:56:13 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_cellul_x : Fill the tab for the cellular automaton with the right cond
*/

#include "fract_ol.h"

void	ft_cellul_1(unsigned char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < HIGHT * 2)
	{
		j = 0;
		while (j < WIDTH * 2)
		{
			if (j == 0 || j == (WIDTH * 2) - 1)
				tab[i][j] = 0;
			else if ((tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 1)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	ft_cellul_2(unsigned char **tab)
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
				|| (tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 1))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
		}
		i++;
	}
}

void	ft_cellul_3(unsigned char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < HIGHT * 2)
	{
		j = 0;
		while (j < WIDTH * 2)
		{
			if (j == 0 || j == (WIDTH * 2) - 1)
				tab[i][j] = 0;
			else if ((tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 1)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0)
				|| (tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	ft_cellul_4(unsigned char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < HIGHT * 2)
	{
		j = 0;
		while (j < WIDTH * 2)
		{
			if (j == 0 || j == (WIDTH * 2) - 1)
				tab[i][j] = 0;
			else if ((tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 0)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	ft_cellul_5(unsigned char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < HIGHT * 2)
	{
		j = 0;
		while (j < WIDTH * 2)
		{
			if (j == 0 || j == (WIDTH * 2) - 1)
				tab[i][j] = 0;
			else if ((tab[i - 1][j - 1] == 1 && tab[i - 1][j] == 1
					&& tab[i - 1][j + 1] == 0)
				|| (tab[i - 1][j - 1] == 0 && tab[i - 1][j] == 0
					&& tab[i - 1][j + 1] == 0))
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
			j++;
		}
		i++;
	}
}
