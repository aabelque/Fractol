/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:36:59 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/11 18:07:31 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		burningship2(t_thrdata *e, intmax_t x, intmax_t y,
		double *deg)
{
	int			i;
	double	tmp;
	double	ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = (double)x / e->fra->zoom + e->fra->x1;
	c.i = (double)y / e->fra->zoom + e->fra->y1;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i
			+ c.r;
		z.i = fabsl(2 * z.i * ztmp) + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			*deg = log(tmp / log((e->fra->smth))) / log(e->fra->smth);
			return (i);
		}
	}
	return (i);
}

void			*burningship(void *arg)
{
	intmax_t	x;
	intmax_t	y;
	int			i;
	double	deg;
	t_thrdata	*e;

	e = (t_thrdata *)arg;
	x = e->i_thr;
	while (x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			i = burningship2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, e->ptf->ptcol4());
			else
				set_pxl(e->img, x, y, interpol_color2(e->ptf->ptcol1(),
							e->ptf->ptcol2(),
							e->ptf->ptcol3(), (((double)i + (1 - deg))
								/ ((double)e->fra->i_max))));
		}
		x += NB_THR;
	}
	pthread_exit(NULL);
}
