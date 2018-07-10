/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 06:02:48 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/10 12:40:38 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		julia2(t_thrdata *e, intmax_t x, intmax_t y,
		double *deg)
{
	int			i;
	double	tmp;
	double	ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = (double)x / e->fra->zoom + e->fra->x1;
	z.i = (double)y / e->fra->zoom + e->fra->y1;
	c.r = e->fra->julcr;
	c.i = e->fra->julci;
	while (++i < e->fra->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			*deg = log(tmp / log(e->smth)) / log(e->smth);
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
	double deg;
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
				set_pxl(e->img, x, y, e->ptf->ptcol4());
			else
				set_pxl(e->img, x, y, interpol_color2(e->ptf->ptcol1(),
							e->ptf->ptcol2(),
							e->ptf->ptcol3(), (((double)i + (1 - deg))
						/ ((double)e->fra->i_max))));
		}
		x += NB_THR;
	}
	return (NULL);
}

void			julia_move(t_env *e, int x, int y)
{
	double	jx;
	double	jy;

	x -= e->x_win / 2;
	y -= e->y_win / 2;
	jx = ((double)x / e->x_win) * 2;
	jy = ((double)y / e->y_win) * 2;
	e->fra.julcr = jx;
	e->fra.julci = jy;
}
