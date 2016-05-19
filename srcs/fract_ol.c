/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:51:43 by semartin          #+#    #+#             */
/*   Updated: 2016/04/12 12:52:01 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_usage_error : Show usage
** -----------------------------------------------------------------------------
** ft_all_init : Initialise the struct t_all
** -----------------------------------------------------------------------------
** ft_help : Print the help message
*/

#include "fract_ol.h"

static void		ft_usage_error(void)
{
	ft_putstr_fd("usage: fract_ol [julia/", 2);
	ft_putendl_fd("mandelbrot/cellul/ikeda/pythagore/newton]", 2);
	exit(0);
}

static t_fract	*all_init(void)
{
	t_fract	*all;

	all = malloc(sizeof(*all));
	all->julia = 0;
	all->mandelbrot = 0;
	all->cellul = 0;
	all->ikeda = 0;
	all->pythagore = 0;
	all->newton = 0;
	return (all);
}

static void		ft_help(void)
{
	ft_putendl("Julia / Mandelbrot / Newton : ");
	ft_putendl("1) 1 to 9 (on num pad) --> Change color");
	ft_putendl("2) - and + -->  Change precision");
	ft_putendl("3) Clic then Page up / Down --> Zoom in / out");
	ft_putendl("4) Press z --> Enable zoom with mouse ");
	ft_putendl("\nOn Julia only : c --> Enable constant change");
	ft_putendl("\nOn Newton only : c --> Change polynomial");
	ft_putendl("\nOn Cellul only :");
	ft_putendl("1) 1 to 6 (on num pad) --> Change cellul path");
	ft_putendl("2) - and + -->  Negative / Positive");
}

int				main(int ac, char **av)
{
	t_fract	*all;

	all = all_init();
	if (ac != 2)
		ft_usage_error();
	if (ft_strcmp(av[1], "julia") == 0)
		all->julia = 1;
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		all->mandelbrot = 1;
	else if (ft_strcmp(av[1], "cellul") == 0)
		all->cellul = 1;
	else if (ft_strcmp(av[1], "ikeda") == 0)
		all->ikeda = 1;
	else if (ft_strcmp(av[1], "pythagore") == 0)
		all->pythagore = 1;
	else if (ft_strcmp(av[1], "newton") == 0)
		all->newton = 1;
	else
		ft_usage_error();
	ft_help();
	ft_minilibx(all);
	return (0);
}
