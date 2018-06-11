/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:45:01 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/11 18:17:25 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			bb_init(t_bb *bb, int width, int height, int iter, int nebula)
{
	bb->esc = ft_memalloc(sizeof(char) * width * height);
	bb->cntesc = ft_memalloc(sizeof(long double) * width * height);
	//b->img->addr = ft_memalloc(sizeof(char) * width * height * 4);
	bb->max = 0;
	bb->wth = width;
	bb->hgt = height;
	bb->iter = iter;
	bb->maxoffs = width * height - 1;
	bb->nebula = nebula;
	bb->cntfreq = NULL;
}

void			bb_free(t_bb *bb)
{
	free(bb->esc);
	free(bb->cntesc);
//	free(b->bb->img);
	if (bb->cntfreq)
		free(bb->cntfreq);
}

int				rgb(double r, double g, double b)
{
	return (((int)(r * 255) << 16) + ((int)(g * 255) << 8)
			+ ((int)(b * 255)));
}

int				rank_int_perc(t_bb *bb, int lo, int hi, int c)
{
	double		cl;
	double		ch;

	cl = bb->prctlim[lo];
	ch = bb->prctlim[hi];
	return (((double)c - cl) / (ch - cl));
}

int				getcolor(t_bb *bb, int cnt)
{
	double		a;

	if (cnt == 0)
		return (0);
	if (cnt <= bb->prctlim[1])
	{
		a = rank_int_perc(bb, 0, 1, cnt);
		return (rgb(0, 0, a));
	}
	if (cnt <= bb->prctlim[2])
	{
		a = rank_int_perc(bb, 1, 2, cnt);
		return (rgb(a, 0, 1));
	}
	if (cnt <= bb->prctlim[4])
	{
		a = rank_int_perc(bb, 2, 4, cnt);
		return (rgb(1, 0, 1 - a));
	}
	if (cnt <= bb->prctlim[5])
	{
		a = rank_int_perc(bb, 4, 5, cnt);
		return (rgb(1, a, 0));
	}
	if (cnt <= bb->prctlim[6])
	{
		a = rank_int_perc(bb, 5, 6, cnt);
		return (rgb(1 - a, 1, 0));
	}
	if (cnt < bb->prctlim[7])
	{
		a = rank_int_perc(bb, 6, 7, cnt);
		return (rgb(0, 1, a));
	}
	a = rank_int_perc(bb, 7, 9, cnt);
	return (rgb(a, 1, 1));
}

complex	double	pxcx(t_bb *bb, int x, int y)
{
	return (((3.0 / bb->wth * (double)x) - 2) +
		((2.0 / bb->hgt * (double)y) - 1) * I);
}

void			cxpx(t_bb *bb, complex double z, int *x, int *y)
{
	*x = (int)((creal(z) + 2) * bb->wth / 3);
	*y = (int)((cimag(z) + 1) * bb->hgt / 2);
}

int				iterate(t_bb *bb, int x, int y, void (*cb)(t_bb*,
			complex double))
{
	complex double	z;
	complex double	c;
	int				i;

	z = 0;
	c = pxcx(bb, x, y);
	i = 1;
	while (i++ < bb->iter)
	{
		z = z * z + c;
		if (cabs(z) >= 2)
			break ;
		if (cb != NULL)
			cb(bb, z);
	}
	return (i);
}

void			putpixel(t_img *b, int c, int x, int y)
{
    int offs;

	offs = (y * b->s_line) + (x * 4);
    b->addr[offs] = RED(c);
    b->addr[offs + 1] = GREEN(c);
    b->addr[offs + 2] = BLUE(c);
}

void			bb_calc_esc(t_thrdata *b, t_bb *bb)
{
	int			x;
	int			y;
	int			offs;
	int			its;

	x = b->i_thr;
	while (x < bb->wth)
	{
		y = 0;
		while (y++ < bb->hgt)
		{
			offs = y * bb->wth + x;
			its = iterate(bb, x, y, NULL);
			if (its != ITER)
				bb->esc[offs] = 1;
			else
				bb->esc[offs] = 0;
		}
		x += NB_THR;
	}
}

void			bb_plot_callb(t_bb *bb, complex double z)
{
	int			x;
	int			y;
	int			offs;

	cxpx(bb, z, &x, &y);
	offs = y * bb->wth + x;
	if (offs < 0 || offs > bb->maxoffs)
		return ;
	bb->cntesc[offs]++;
	if (bb->cntesc[offs] > bb->max)
		bb->max = bb->cntesc[offs];
}

void			bb_plot_esc(t_thrdata *b, t_bb *bb)
{
	int			x;
	int			y;
	int			offs;

	x = b->i_thr;
	while (x < bb->wth)
	{
		y = 0;
		while (y++ < bb->hgt)
		{
			offs = y * bb->wth + x;
			if (bb->esc[offs] == 1)
				iterate(bb, x, y, &bb_plot_callb);
		}
		x += NB_THR;
	}
}

void			bb_draw(t_thrdata *b, t_bb *bb)
{
	int			x;
	int			y;
	int			offs;
	int			cnt;
	double		c;

	x = b->i_thr;
	while (x < bb->wth)
	{
		y = 0;
		while (y++ < bb->hgt)
		{
			offs = y * bb->wth + x;
			cnt = bb->cntesc[offs];
			c = getcolor(bb, cnt);
			putpixel(b->img, c, x, y);
		}
		x += NB_THR;
	}
}

void			bb_cmp_stat(t_bb *bb)
{
	int 		i;
	long double	sum;
	int 		n;
	long 		c;
	double 		d;
	double 		lim;
	int 		cum_f;
	int 		p;

	i = 0;
	sum = 0;
	n = 0;
	bb->cntfreq = ft_memalloc(sizeof(long double) * bb->max);
	while (i <= bb->maxoffs)
	{
		c = bb->cntesc[i];
		if (c)
		{
			bb->cntfreq[c]++;
			n++;
			sum += c;
		}
		i++;
	}
	bb->mean = (long double)sum / n;
	bb->numesc = n;
	d = (long double)n / 10;
	lim = d;
	cum_f = 0;
	p = 0;
	i = 0;
	while (i < bb->max)
	{
		cum_f += bb->cntfreq[i];
		if (cum_f > lim)
		{
			bb->prctlim[p++] = i;
			lim += d;
		}
		if (p == 10)
			break ;
		i++;
	}
	bb->prctlim[9] = bb->max;
}

void			bb_calc(t_thrdata *b, t_bb *bb)
{
	bb_calc_esc(b, bb);
	bb_plot_esc(b, bb);
	bb_cmp_stat(bb);
	bb_draw(b, bb);
}

void			*launch_bb(void *arg)
{
	t_thrdata	*thr;
	t_bb		bb;

	thr = (t_thrdata *)arg;
	//bb = ft_memalloc(sizeof(t_bb));
	bb_init(&bb, X_WIN, Y_WIN, ITER, 0);
	bb_calc(thr, &bb);
	//bb_free(b);
	return (0);
}
