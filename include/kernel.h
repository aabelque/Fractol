/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:16:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 15:40:01 by aabelque         ###   ########.fr       */
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
#endif
