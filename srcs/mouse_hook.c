/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:06 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/05 13:32:21 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		zoom_upm(t_env *e, int x, int y)
{
	long double	p;
	long double	sh;

	sh = (0.1 * (e->fra.y2 - e->fra.y1)) / 2;
	p = (long double)y / (long double)Y_WIN;
	e->fra.y1 += sh * p;
	e->fra.y2 -= sh * (1 - p);
	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	p = (long double)x / (long double)X_WIN;
	e->fra.x1 += sh * p;
	e->fra.x2 -= sh * (1 - p);
	e->fra.zoom = e->x_win / (e->fra.x2 - e->fra.x1);
}

static void		zoom_dom(t_env *e, int x, int y)
{
	long double	p;
	long double	sh;

	sh = (0.1 * (e->fra.y2 - e->fra.y1)) / 2;
	p = (long double)y / (long double)Y_WIN;
	e->fra.y1 -= sh * p;
	e->fra.y2 += sh * (1 - p);
	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	p = (long double)x / (long double)X_WIN;
	e->fra.x1 -= sh * p;
	e->fra.x2 += sh * (1 - p);
	e->fra.zoom = e->x_win / (e->fra.x2 - e->fra.x1);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == M_SCUP || button == K_PLUS)
		zoom_upm(e, x, y);
	if (button == M_SCDO || button == K_LESS)
		zoom_dom(e, x, y);
	if (button == M_LC)
		julia_move(e, x, y);
	if (button == M_RC)
		init_env2(e, 0.285, 0.01);
	expose_hook(e);
	return (0);
}
