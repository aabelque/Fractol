/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:47:19 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/07 16:28:10 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			zoom_upk(t_env *e)
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

void			zoom_dok(t_env *e)
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

static	int		key_hook2(int keycode, t_env *e)
{
	if (keycode == K_I)
		e->keybd = 7;
	if (keycode == K_U)
		e->keybd = 8;
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	if (keycode == K_PLUS)
		e->keybd = 1;
	if (keycode == K_LESS)
		e->keybd = 2;
	if (keycode == K_UP)
		e->keybd = 3;
	if (keycode == K_DOWN)
		e->keybd = 4;
	if (keycode == K_RIGHT)
		e->keybd = 5;
	if (keycode == K_LEFT)
		e->keybd = 6;
	if (keycode == K_P)
		e->fra.n += 0.2;
	if (keycode == K_O)
		e->fra.n -= 0.2;
	key_hook2(keycode, e);
	return (0);
}
