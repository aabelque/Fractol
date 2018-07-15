/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:13:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/15 14:35:49 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <pthread.h>

# ifdef __APPLE__
#  include <OpenCL/cl.h>
# else
#  include <CL/cl.h>
# endif

# define X_WIN 1280
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
	K_C7 = 26,
	K_X = 7,
	K_CC,
	K_W = 13,
	K_A = 0,
	K_S,
	K_D,
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
	F_TREE,
	F_SPONGE,
	F_TRI,
	F_MAX
};

typedef	struct		s_fractal
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zoom;
	float			julcr;
	float			julci;
	float			n;
	float			size_tree;
	float			size_tree2;
	float			i_max2;
	float			smth;
	float			deg;
	float			r_freq;
	float			g_freq;
	float			b_freq;
	float			r_ph;
	float			g_ph;
	float			b_ph;
	int				clr;
	int				clr2;
	int				col_style;
	int				psych;
	int				r;
	int				g;
	int				b;
	int				sc;
	int				i_max;
}					t_fractal;

typedef	struct		s_opencl
{
	cl_device_type		dev_type;
	float				deg;
	cl_int				err;
	cl_uint				num_dev;
	size_t				local;
	size_t				img_s;
	size_t				imgxy[2];
	int					*bufhst;
	float				bufdeg;
	cl_mem				input;
	cl_mem				output;
	cl_mem				col;
	char				*kernel_src;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel[4];
	t_fractal			fra;
}					t_opencl;

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

typedef struct		s_cmplx
{
	float			r;
	float			i;
}					t_cmplx;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				s_line;
	int				endian;
	float			x;
	float			y;
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
	int				it;
	int				device;
	float			x_win;
	float			y_win;
	void			*(*func[F_MAX])(void *arg);
	pthread_t		thread[NB_THR];
	t_img			img;
	t_fractal		fra;
	t_ptfunc		ptf;
	t_opencl		opcl;
}					t_env;

void				setup_col(t_fractal *c);
void				col_pal(t_fractal *c);
void				color_random(t_fractal *c);
void				psych_col_rand(t_fractal *c);
int					ch_col(t_fractal *c, float iter);
int					col_hook(t_fractal *c);
void				opencl_init(t_opencl *opcl, t_env *e);
void				opencl_draw(t_opencl *opcl, t_env *e, float deg);
void				set_opencl_env(t_opencl *opcl);
void				create_prog(t_opencl *opcl);
char				*get_kernel_source(char *file);
void				create_kernel(cl_program program, cl_kernel *kernel,
		const char *func);
void				send_tree(t_env *e, int iter);
void				tree(t_env *e, t_tree start, float angle,
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
t_color				interpol_color(t_color a, t_color b, float i);
t_color				interpol_color2(t_color a, t_color b, t_color c, float i);
void				init_env(t_env *e);
void				init_env2(t_env *e, float x, float y);
void				init_env3(t_env *e);
void				init_env4(t_env *e);
void				init_env5(t_env *e);
void				clean(t_env *e);
void				*mandelbrot(void *arg);
void				*tricorn(void *arg);
void				*buddhabrot(void *arg);
void				*multibrot(void *arg);
void				*julia(void *arg);
void				ft_error(char *str);
void				ft_malloc_error(t_env *e);
void				ft_usage(void);
//void				init_color_gpu(t_fractal c);
int					init_mlx(t_env *e);
int					loop_hook(t_env *e);
int					parsing_arg(char *str, char *s, t_env *e);
int					parsing_arg2(char *str, char *s, t_env *e);
int					main(int ac, char **av);
#endif
