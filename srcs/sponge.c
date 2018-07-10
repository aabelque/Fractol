/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sponge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:13:38 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/10 16:39:19 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		sponge2(t_thrdata *e, intmax_t x, intmax_t y)
{
	int			i;

	i = 0;
	e->fra->zoom = (e->fra->zoom >= 5) ? 1.6 : e->fra->zoom;
	e->fra->zoom = (e->fra->zoom <= 0.6) ? 1.6 : e->fra->zoom;
	x = (x) / e->fra->zoom;
	y = (y) / e->fra->zoom;
	x = labs(x);
	y = labs(y);
	while ((x > 0 || y > 0) && i < e->fra->i_max)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);
}

void			*sponge(void *arg)
{
	intmax_t	x;
	intmax_t	y;
	int			i;
	int			color;
	t_thrdata	*e;

	e = (t_thrdata *)arg;
	x = e->i_thr;
	while (x < X_WIN)
	{
		y = -1;
		while (++y < Y_WIN)
		{
			i = sponge2(e, x, y);
			color = (((255 + i * e->fra->r) << 16)
					+ ((255 + i * e->fra->g) << 8)
					+ (255 + i * e->fra->b));
			if (i != e->fra->i_max)
				set_pxl2(*e->img, x, y, color);
		}
		x += NB_THR;
	}
	pthread_exit(NULL);
}
