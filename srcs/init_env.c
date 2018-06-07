/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:25:46 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/07 09:17:21 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_env(t_env *e)
{
	long double	p;

	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.x1 = -2.6;
	e->fra.x2 = 2.2;
	p = (e->fra.x2 - e->fra.x1) / X_WIN;
	e->fra.y1 = -(p * Y_WIN) / 2;
	e->fra.y2 = -e->fra.y1;
	e->fra.zoom = X_WIN / ((e->fra.x2 - e->fra.x1));
	e->fra.i_max = 50;
	e->fra.n = 3;
}

void			init_env2(t_env *e, long double x, long double y)
{
	long double	p;

	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.x1 = -2.0;
	e->fra.x2 = 2.0;
	p = (e->fra.x2 - e->fra.x1) / X_WIN;
	e->fra.y1 = -(p * Y_WIN) / 2;
	e->fra.y2 = -e->fra.y1;
	e->fra.julcr = x;
	e->fra.julci = y;
	e->fra.zoom = X_WIN / (e->fra.x2 - e->fra.x1);
	e->fra.i_max = 150;
}

void			init_env3(t_env *e)
{
	long double	p;

	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.x1 = -2.6;
	e->fra.x2 = 1.6;
	p = (e->fra.x2 - e->fra.x1) / X_WIN;
	e->fra.y1 = -(p * Y_WIN) / 2 - 0.5;
	e->fra.y2 = -e->fra.y1 - 0.5;
	e->fra.zoom = X_WIN / ((e->fra.x2 - e->fra.x1));
	e->fra.i_max = 50;
	e->fra.n = 3;
}
