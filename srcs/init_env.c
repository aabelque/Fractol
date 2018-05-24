/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:25:46 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/24 17:39:29 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_env(t_env *e)
{
	long double	p;

	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.x1 = -2.6;
	e->fra.x2 = 1.2;
	p = (e->fra.x2 - e->fra.x1) / X_WIN;
	e->fra.y1 = -(p * Y_WIN) / 2;
	e->fra.y2 = -e->fra.y1;
	e->fra.zoom = X_WIN / ((e->fra.x2 - e->fra.x1));
	e->fra.i_max = 50;
	e->n = 3;
}

void			init_env2(t_env *e)
{
	long double	p;

	e->x_win = X_WIN;
	e->y_win = Y_WIN;
	e->fra.x1 = -2.0;
	e->fra.x2 = 2.0;
	p = (e->fra.x2 - e->fra.x1) / X_WIN;
	e->fra.y1 = -(p * Y_WIN) / 2;
	e->fra.y2 = -e->fra.y1;
	e->fra.zoom = X_WIN / (e->fra.x2 - e->fra.x1);
	e->fra.i_max = 150;
}
