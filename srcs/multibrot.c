/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:41:03 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/11 18:07:52 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		multibrot2(t_thrdata *e, intmax_t x, intmax_t y,
		float *deg)
{
	int			i;
	float	tmp;
	float	ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z = (t_cmplx){0, 0};
	c.r = (float)x / e->fra->zoom + e->fra->x1;
	c.i = (float)y / e->fra->zoom + e->fra->y1;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = pow((z.r * z.r) + (z.i * z.i), e->fra->n / 2)
			* cos(e->fra->n * atan2(z.i, z.r)) + c.r;
		z.i = pow((ztmp * ztmp) + (z.i * z.i), e->fra->n / 2)
			* sin(e->fra->n * atan2(z.i, ztmp)) + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			*deg = log(tmp / log(e->fra->smth)) / log(e->fra->smth);
			return (i);
		}
	}
	return (i);
}

void			*multibrot(void *arg)
{
	intmax_t	x;
	intmax_t	y;
	int			i;
	float deg;
	t_thrdata	*e;

	e = (t_thrdata *)arg;
	x = e->i_thr;
	while (x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			i = multibrot2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, e->ptf->ptcol4());
			else
				set_pxl(e->img, x, y, interpol_color2(e->ptf->ptcol1(),
							e->ptf->ptcol2(),
							e->ptf->ptcol3(), (((float)i + (1 - deg))
								/ ((float)e->fra->i_max))));
		}
		x += NB_THR;
	}
	pthread_exit(NULL);
}
