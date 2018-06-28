/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:16:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/28 13:59:35 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KERNEL_H
# define KERNEL_H

typedef	struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

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
	float			smth;
	int				r;
	int				g;
	int				b;
	int				i_max;
	float			i_max2;
}					t_fractal;
#endif
