/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:13:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/08 17:00:51 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define X_WIN 1600
# define Y_WIN 900

# define IMG_X 270
# define IMG_Y 240

# define NB_THR 4

enum				e_mouse
{
	M_SCUP = 4,
	M_SCDO = 5,
	M_LC = 1,
	M_RC
};

enum				e_key
{
	K_ESC = 53,
	K_PLUS = 69,
	K_LESS = 78,
	K_1 = 18,
	K_2,
	K_3,
	K_4,
	K_P = 35,
	K_O = 31,
	K_I = 34,
	K_U = 32,
	K_SP = 49,
	K_C1 = 83,
	K_C2,
	K_C3,
	K_C4,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
};

enum				e_fracts
{
	F_MANDEL,
	F_JULIA,
	F_MANDEL2,
	F_BURNIN,
	F_MAX
};

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
	long double		zoom;
	long double		julcr;
	long double		julci;
	long double		n;
	int				i_max;
}					t_fractal;

typedef struct		s_cmplx
{
	long double		r;
	long double		i;
}					t_cmplx;

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

typedef	struct		s_ptfunc
{
	t_color			(*ptcol1)(void);
	t_color			(*ptcol2)(void);
	t_color			(*ptcol3)(void);
	t_color			(*ptcol4)(void);
	t_color			(*ptcol5)(void);
}					t_ptfunc;

typedef struct		s_thrdata
{
	int				i_thr;
	t_fractal		*fra;
	t_img			*img;
	t_ptfunc		*ptf;
}					t_thrdata;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fractol;
	int				mouse;
	int				keybd;
	int				keycol;
	long double		x_win;
	long double		y_win;
	void			*(*func[F_MAX])(void *arg);
	pthread_t		thread[NB_THR];
	t_img			img;
	t_fractal		fra;
	t_ptfunc		ptf;
	t_color			c;
}					t_env;

void				change_color(t_env *e);
int					key_quit(t_env *e);
void				init_funct(t_env *e);
void				init_color(t_env *e);
void				send_thread(t_env *e);
void				julia_move(t_env *e, int x, int y);
void				*burningship(void *arg);
void				move_up(t_env *e);
void				zoom_upk(t_env *e);
void				zoom_dok(t_env *e);
void				move_do(t_env *e);
void				move_r(t_env *e);
void				move_l(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					key_release_hook(int keycode, t_env *e);
int					key_press(t_env *e);
void				set_pxl(t_img *e, int x, int y, t_color color);
t_color				color_r(void);
t_color				color_g(void);
t_color				color_b(void);
t_color				color_bl(void);
t_color				color_bc(void);
t_color				color_y(void);
t_color				interpol_color(t_color a, t_color b, double i);
t_color				interpol_color2(t_color a, t_color b, t_color c, double i);
void				init_env(t_env *e);
void				init_env2(t_env *e, long double x, long double y);
void				init_env3(t_env *e);
void				clean(t_env *e);
void				*mandelbrot(void *arg);
void				*mandelbrot3(void *arg);
void				*julia(void *arg);
void				ft_error(char *str);
void				ft_malloc_error(t_env *e);
void				ft_usage(void);
int					init_mlx(t_env *e);
int					loop_hook(t_env *e);
int					parsing_arg(char *str, t_env *e);
int					parsing_arg2(char *str, t_env *e);
int					main(int ac, char **av);
#endif
