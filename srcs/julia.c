/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 06:02:48 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/07 09:56:45 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		julia2(t_thrdata *e, intmax_t x, intmax_t y,
		long double *deg)
{
	int			i;
	long double	tmp;
	long double	ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = (long double)x / e->fra->zoom + e->fra->x1;
	z.i = (long double)y / e->fra->zoom + e->fra->y1;
	c.r = e->fra->julcr;
	c.i = e->fra->julci;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = z.r * z.r + z.i * z.i;
		if (tmp >= 4)
		{
			*deg = log10l(log10l(tmp)) / log10l(2);
			return (i);
		}
	}
	return (i);
}

void			*julia(void *arg)
{
	intmax_t	x;
	intmax_t	y;
	int			i;
	long double deg;
	t_thrdata	*e;

	e = (t_thrdata *)arg;
	x = e->i_thr;
	while (x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			i = julia2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, color_bc());
			else
				set_pxl(e->img, x, y, interpol_color(color_bl(), color_b(),
							(((double)i + (1 - deg))
						/ ((double)e->fra->i_max))));
		}
		x += NB_THR;
	}
	return (NULL);
}

void			julia_move(t_env *e, int x, int y)
{
	long double	jx;
	long double	jy;

	jx = ((long double)x - e->x_win / 2) / 1500;
	jy = ((long double)y - e->y_win / 2) / 1500;
	e->fra.julcr = jx;
	e->fra.julci = jy;
}
