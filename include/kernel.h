/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:16:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/10 16:39:19 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KERNEL_H
# define KERNEL_H

typedef	struct		s_cmplx
{
	float			r;
	float			i;
}					t_cmplx;

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
	float			x_win;
	float			y_win;
	float			size_tree;
	float			size_tree2;
	float			smth;
	int				r;
	int				g;
	int				b;
	int				i_max;
	float			i_max2;
}					t_fractal;

typedef struct		s_env
{
	//void			*mlx;
	//void			*win;
	int				fractol;
	int				mouse;
	int				keybd;
	int				keycol;
	int				keyf;
	int				it;
	int				device;
	float		x_win;
	float		y_win;
	float		smth;
	//void			*(*func[F_MAX])(void *arg);
	//pthread_t		thread[NB_THR];
	//t_img			img;
	t_fractal		fra;
	//t_ptfunc		ptf;
	//t_opencl		opcl;
}					t_env;
#endif
