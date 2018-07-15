/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:30:59 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/15 14:26:02 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		tricorn2(t_thrdata *e, intmax_t x, intmax_t y,
		float *deg)
{
	int			i;
	float		tmp;
	float		ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = (float)x / e->fra->zoom + e->fra->x1;
	c.i = (float)y / e->fra->zoom + e->fra->y1;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = -2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			*deg = log(tmp / log(e->fra->smth)) / log(e->fra->smth);
			return (i);
		}
	}
	return (i);
}

static t_color	tri_help(t_thrdata *e, float deg, int i)
{
	return (interpol_color2(e->ptf->ptcol1(), e->ptf->ptcol2(),
				e->ptf->ptcol3(), (((float)i + (1 - deg))
					/ ((float)e->fra->i_max))));
}

void			*tricorn(void *arg)
{
	intmax_t	x;
	intmax_t	y;
	int			i;
	float		deg;
	t_thrdata	*e;

	e = (t_thrdata *)arg;
	x = e->i_thr;
	while (x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			i = tricorn2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, e->ptf->ptcol4());
			else
			{
				(e->fra->sc == 1) ? set_pxl2(*e->img, x, y, ch_col(e->fra, deg))
					: set_pxl(e->img, x, y, tri_help(e, deg, i));
			}
		}
		x += NB_THR;
	}
	pthread_exit(NULL);
}
