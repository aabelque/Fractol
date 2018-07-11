/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:25:46 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/11 17:53:38 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_env(t_env *e)
{
	float	p;

	init_color(e);
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
	e->smth = 5000.0;
	e->keyf = 0;
}

void			init_env2(t_env *e, float x, float y)
{
	float	p;

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
	e->fra.i_max = 50;
	e->mouse = 1;
	e->smth = 5000.0;
	e->keyf = 0;
}

void			init_env3(t_env *e)
{
	float	p;

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
	e->smth = 5000.0;
	e->keyf = 0;
}

void			init_env4(t_env *e)
{
	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.zoom = 1;
	e->fra.i_max = 10;
	e->keyf = 0;
	e->fra.r = -255;
	e->fra.g = -255;
	e->fra.b = -255;
}

void			init_env5(t_env *e)
{
	e->fra.x1 = 0;
	e->fra.x2 = -100;
	e->fra.zoom = 1.;
	e->fra.i_max2 = 11.0;
	e->fra.size_tree = 0.5;
	e->fra.size_tree2 = 0.5;
	e->fra.r = 5;
	e->fra.g = 10;
	e->fra.b = 1;
	e->mouse = 1;
	e->keyf = 0;
}
