/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:30:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/11 18:47:26 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_pxl(t_img *e, int x, int y, t_color color)
{
	int		pxl;

	pxl = (x * 4) + (y * e->s_line);
	e->addr[pxl] = color.b;
	e->addr[++pxl] = color.g;
	e->addr[++pxl] = color.r;
	e->addr[++pxl] = color.a;
}

void		set_pxl2(t_img e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xff0000) >> 16;
	g = (color & 0xff00) >> 8;
	b = (color & 0xff);
	if (x >= 0 && y >= 0 && x < X_WIN && y < Y_WIN)
	{
		e.addr[(y * e.s_line) + ((e.bpp / 8) * x) + 2] = r;
		e.addr[(y * e.s_line) + ((e.bpp / 8) * x) + 1] = g;
		e.addr[(y * e.s_line) + ((e.bpp / 8) * x)] = b;
	}
}
