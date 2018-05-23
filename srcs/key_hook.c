/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:47:19 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/23 19:03:34 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		zoom_upk(t_env *e)
{
	long double sh;

	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	e->fra.y1 += sh;
	e->fra.y2 -= sh;
	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	e->fra.x1 += sh;
	e->fra.x2 -= sh;
	e->fra.zoom = e->x_win / (e->fra.x2 - e->fra.x1);
}

static void		zoom_dok(t_env *e)
{
	long double sh;

	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	e->fra.y1 -= sh;
	e->fra.y2 += sh;
	sh = (0.1 * (e->fra.x2 - e->fra.x1)) / 2;
	e->fra.x1 -= sh;
	e->fra.x2 += sh;
	e->fra.zoom = e->x_win / (e->fra.x2 - e->fra.x1);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	if (keycode == K_PLUS)
		zoom_upk(e);
	if (keycode == K_LESS)
		zoom_dok(e);
	if (keycode == K_UP)
		move_up(e);
	if (keycode == K_DOWN)
		move_do(e);
	if (keycode == K_RIGHT)
		move_r(e);
	if (keycode == K_LEFT)
		move_l(e);
	expose_hook(e);
	return (0);
}
