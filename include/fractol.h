/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:13:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/17 11:35:06 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define X_WIN 1024
# define Y_WIN 720

# define NB_THR 16

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
	K_5 = 23,
	K_6 = 22,
	K_P = 35,
	K_O = 31,
	K_I = 34,
	K_U = 32,
	K_SP = 49,
	K_C0 = 82,
	K_C1 = 83,
	K_C2,
	K_C3,
	K_C4,
	K_C5,
	K_C6,
	K_X = 7,
	K_F16 = 106,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
};

enum				e_fracts
{
	F_MANDEL,
	F_JULIA,
	F_MULTI,
	F_BURNIN,
	F_BUDDHA,
	F_TREE,
	F_SPONGE,
	F_MAX
};

typedef	struct		s_tree
{
	int				x;
	int				y;
}					t_tree;

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
	long double		size_tree;
	long double		size_tree2;
	int				r;
	int				g;
	int				b;
	int				i_max;
	long double		i_max2;
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
}					t_ptfunc;

typedef struct		s_thrdata
{
	int				i_thr;
	long double		smth;
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
	int				keyf;
	long double		x_win;
	long double		y_win;
	long double		smth;
	void			*(*func[F_MAX])(void *arg);
	pthread_t		thread[NB_THR];
	t_img			img;
	t_fractal		fra;
	t_ptfunc		ptf;
}					t_env;

void				send_tree(t_env *e, int iter);
void				tree(t_env *e, t_tree start, long double angle,
		int iter);
void				tree_move(t_env *e, int x, int y);
void				set_pxl2(t_img e, int x, int y, int color);
void				change_color(t_env *e);
void				change_color2(t_env *e);
void				change_color3(t_env *e);
void				change_color4(t_env *e);
void				change_color5(t_env *e);
void				change_color6(t_env *e);
int					key_quit(t_env *e);
void				init_funct(t_env *e);
void				init_color(t_env *e);
void				send_thread(t_env *e);
void				julia_move(t_env *e, int x, int y);
void				*burningship(void *arg);
void				*sponge(void *arg);
void				move_up(t_env *e);
void				zoom_upk(t_env *e);
void				zoom_dok(t_env *e);
void				move_do(t_env *e);
void				move_r(t_env *e);
void				move_l(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					key_hook3(int keycode, t_env *e);
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
void				init_env4(t_env *e);
void				init_env5(t_env *e);
void				clean(t_env *e);
void				*mandelbrot(void *arg);
void				*buddhabrot(void *arg);
void				*multibrot(void *arg);
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
