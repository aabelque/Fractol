/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:29:30 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/25 06:02:34 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		mandelbrot2(t_env *e)
{
	int			i;
	long double	tmp;

	i = -1;
	while (++i < e->fra.i_max)
	{
		e->fra.tmp = e->fra.zr;
		e->fra.zr = pow((e->fra.zr * e->fra.zr) +
				(e->fra.zi * e->fra.zi), e->n / 2)
			* cos(e->n * atan2(e->fra.zi, e->fra.zr)) + e->fra.cr;
		e->fra.zi = pow((e->fra.tmp * e->fra.tmp) +
				(e->fra.zi * e->fra.zi), e->n / 2)
			* sin(e->n * atan2(e->fra.zi, e->fra.tmp)) + e->fra.ci;
		tmp = e->fra.zr * e->fra.zr + e->fra.zi * e->fra.zi;
		if (tmp >= 4)
		{
			e->deg = log(log(tmp)) / log(e->n);
			return (i);
		}
	}
	return (i);
}

void			mandelbrot3(t_env *e)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	x = -1;
	while (++x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			e->fra.zr = 0;
			e->fra.zi = 0;
			e->fra.cr = (long double)x / e->fra.zoom + e->fra.x1;
			e->fra.ci = (long double)y / e->fra.zoom + e->fra.y1;
			i = mandelbrot2(e);
			if (i >= e->fra.i_max)
				set_pxl(e, x, y, color_bc());
			else
				set_pxl(e, x, y, interpol_color2(color_bl(), color_b(),
							color_g(), (((double)i + (1 - e->deg))
								/ ((double)e->fra.i_max))));
		}
	}
}
