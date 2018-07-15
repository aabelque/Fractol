/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 06:02:48 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/15 14:16:37 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		julia2(t_thrdata *e, intmax_t x, intmax_t y,
		float *deg)
{
	int			i;
	float		tmp;
	float		ztmp;
	t_cmplx		z;
	t_cmplx		c;

	i = -1;
	z.r = (float)x / e->fra->zoom + e->fra->x1;
	z.i = (float)y / e->fra->zoom + e->fra->y1;
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
			*deg = log(tmp / log(e->fra->smth)) / log(e->fra->smth);
			return (i);
		}
	}
	return (i);
}

static t_color	julia_help(t_thrdata *e, float deg, int i)
{
	return (interpol_color2(e->ptf->ptcol1(), e->ptf->ptcol2(),
				e->ptf->ptcol3(), (((float)i + (1 - deg))
					/ ((float)e->fra->i_max))));
}

void			*julia(void *arg)
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
			i = julia2(e, x, y, &deg);
			if (i >= e->fra->i_max)
				set_pxl(e->img, x, y, e->ptf->ptcol4());
			else
			{
				(e->fra->sc == 1) ? set_pxl2(*e->img, x, y, ch_col(e->fra, deg))
					: set_pxl(e->img, x, y, julia_help(e, deg, i));
			}
		}
		x += NB_THR;
	}
	return (NULL);
}

void			julia_move(t_env *e, int x, int y)
{
	float	jx;
	float	jy;

	x -= e->x_win / 2;
	y -= e->y_win / 2;
	jx = ((float)x / e->x_win) * 2;
	jy = ((float)y / e->y_win) * 2;
	e->fra.julcr = jx;
	e->fra.julci = jy;
}
