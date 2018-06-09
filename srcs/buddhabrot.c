/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:45:01 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/09 14:05:15 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		buddhabrot2(t_thrdata *e, intmax_t x, intmax_t y,
		long double *deg)
{
	int			i;
	long double	tmp;
	long double	ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = (long double)x / e->fra->zoom + e->fra->x1;
	c.i = (long double)y / e->fra->zoom + e->fra->y1;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = z.r * z.r + z.i * z.i;
		if (tmp >= 10)
		{
			*deg = log(log(tmp)) / log(e->smth);
			return (i);
		}
	}
	return (i);
}

void			*buddhabrot(void *arg)
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
			i = buddhabrot2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, interpol_color2(e->ptf->ptcol1(),
							e->ptf->ptcol2(),
							e->ptf->ptcol3(), (((double)i + (1 - deg))
								/ ((double)e->fra->i_max))));
			else
				set_pxl(e->img, x, y, e->ptf->ptcol4());
					}
		x += NB_THR;
	}
	pthread_exit(NULL);
}