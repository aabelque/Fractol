/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:13:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/25 05:43:00 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define X_WIN 1600
# define Y_WIN 900

# define I_MAX 50
# define SCALE 200

# define IMG_X 270
# define IMG_Y 240

typedef enum		e_mouse
{
	M_SCUP = 4,
	M_SCDO = 5
}					t_mouse;

typedef enum		e_key
{
	K_ESC = 53,
	K_PLUS = 69,
	K_LESS = 78,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP,
	K_P = 35,
	K_O = 31,
	K_I = 34,
	K_U = 32
}					t_key;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef	struct		s_fractal
{
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		tmp;
	long double		zoom;
	int				i_max;
}					t_fractal;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				s_line;
	int				endian;
	long double		x;
	long double		y;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fractol;
	long double		n;
	unsigned int	colorm;
	int				colorv;
	long double		deg;
	long double		x_win;
	long double		y_win;
	t_img			img;
	t_fractal		fra;
	t_color			c;
}					t_env;

void				burningship(t_env *e);
void				move_up(t_env *e);
void				move_do(t_env *e);
void				move_r(t_env *e);
void				move_l(t_env *e);
void				redraw(t_env *e);
int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
unsigned int		colortohex(t_color color);
unsigned int		set_color(int a, t_env *e);
void				set_pxl(t_env *e, int x, int y, t_color color);
t_color				color_r(void);
t_color				color_g(void);
t_color				color_b(void);
t_color				color_bl(void);
t_color				color_bc(void);
t_color				color_y(void);
t_color				interpol_color(t_color a, t_color b, double i);
t_color				interpol_color2(t_color a, t_color b, t_color c, double i);
int					out_map(long double x, long double y);
void				init_env(t_env *e);
void				init_env2(t_env *e);
void				init_env3(t_env *e);
void				clean(t_env *e);
void				mandelbrot(t_env *e);
void				mandelbrot3(t_env *e);
void				julia(t_env *e);
void				ft_error(char *str);
void				ft_malloc_error(t_env *e);
void				ft_usage(void);
int					init_mlx(t_env *e);
int					loop_hook(t_env *e);
int					parsing_arg(char *str, t_env *e);
int					parsing_arg2(char *str, t_env *e);
int					main(int ac, char **av);
#endif
