/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:52:15 by semartin          #+#    #+#             */
/*   Updated: 2016/04/12 12:54:08 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include <libft.h>
# include <mlx.h>
# include <math.h>

# define ECHAP		65307
# define WIDTH		800
# define HIGHT		800

typedef struct		s_complex
{
	double			x;
	double			i;
}					t_complex;

typedef struct		s_fract
{
	int				julia;
	int				mandelbrot;
	int				cellul;
	int				ikeda;
	int				pythagore;
	int				newton;
}					t_fract;

typedef struct		s_env
{
	int				color;
	int				fast;
	int				x;
	int				y;
	int				yk;
	int				xk;
	int				z;
	int				c;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	double			zoom;
	double			xo;
	double			yo;
	t_complex		zc;
	t_fract			*all;
}					t_env;

t_complex			ft_sum_complex(t_complex z1, t_complex z2);
t_complex			ft_diff_complex(t_complex z1, t_complex z2);
t_complex			ft_product_complex(t_complex z1, t_complex z2);
t_complex			ft_div_complex(t_complex z1, t_complex z2);
t_complex			ft_power_complex(t_complex z, int nb);
double				ft_mod_complex(t_complex z);
void				ft_build_julia(t_env *e);
void				ft_pixel_put_image(t_env *e, int x, int y, int color);
void				ft_minilibx(t_fract *all);
double				ft_width(double i, t_env *e);
double				ft_hight(double i, t_env *e);
void				ft_build_mandelbrot(t_env *e);
void				ft_build_newton(t_env *e);
void				ft_build_cellul_1(t_env *e);
void				ft_build_cellul_2(t_env *e);
void				ft_build_cellul_3(t_env *e);
void				ft_build_cellul_4(t_env *e);
void				ft_build_cellul_5(t_env *e);
void				ft_build_cellul_6(t_env *e);
void				ft_build_ikeda(t_env *e);
void				ft_build_pythagore(t_env *e);
int					key_color(int keycode, t_env *e);
void				ft_call_fract(t_env *e);
void				ft_call_julia(t_env *e);
void				ft_call_mandelbrot(t_env *e);
void				ft_call_ikeda(t_env *e);
void				ft_call_cellul(t_env *e);
void				ft_call_pythagore(t_env *e);
void				ft_call_newton(t_env *e);
int					key_escape(int keycode, t_env *e);
int					key_change(int keycode, t_env *e);
int					mouse_zoom(int key, int x, int y, t_env *e);
int					mouse_motion(int x, int y, t_env *e);
int					expose_hook(t_env *e);
void				ft_cellul_1(unsigned char **tab);
void				ft_cellul_2(unsigned char **tab);
void				ft_cellul_3(unsigned char **tab);
void				ft_cellul_4(unsigned char **tab);
void				ft_cellul_5(unsigned char **tab);
void				ft_cellul_6(unsigned char **tab);
void				ft_cellul_algo(t_env *e, unsigned char **tab);

#endif
