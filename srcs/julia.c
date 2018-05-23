/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:23:27 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/23 17:06:37 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		julia2(t_env *e)
{
	int			i;
	long double	tmp;

	i = -1;
	while (++i < e->fra.i_max)
	{
		e->fra.tmp = e->fra.zr;
		e->fra.zr = e->fra.zr * e->fra.zr - e->fra.zi * e->fra.zi
			+ e->fra.cr;
		e->fra.zi = 2 * e->fra.zi * e->fra.tmp + e->fra.ci;
		tmp = e->fra.zr * e->fra.zr + e->fra.zi * e->fra.zi;
		if (tmp >= 4)
		{
			e->deg = log10l(log10l((tmp))) / log10l(2);
			return (i);
		}
	}
	return (i);
}

void			julia(t_env *e)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	x = 0;
	while (++x < X_WIN)
	{
		y = 0;
		while (++y < Y_WIN)
		{
			e->fra.zr = (long double)x / e->fra.zoom + e->fra.x1;
			e->fra.zi = (long double)y / e->fra.zoom + e->fra.y1;
			e->fra.cr = 0.285;
			e->fra.ci = 0.01;
			i = julia2(e);
			if (i >= e->fra.i_max)
				set_pxl(e, x, y, colorBC());
			else
				set_pxl(e, x, y, interpol_color(colorBL(), colorB(),
							(((double)i + (1 - e->deg))
						/ ((double)e->fra.i_max))));
		}
	}
}
