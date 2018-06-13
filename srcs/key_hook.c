/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:47:19 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/13 11:37:53 by aabelque         ###   ########.fr       */
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

static	void	key_change_fractal(int keycode, t_env *e)
{
	if (keycode == K_1)
	{
		e->fractol = F_MANDEL;
		init_env(e);
	}
	if (keycode == K_2)
	{
		e->fractol = F_JULIA;
		init_env2(e, 0.285, 0.01);
	}
	if (keycode == K_3)
	{
		e->fractol = F_MULTI;
		init_env(e);
	}
	if (keycode == K_4)
	{
		e->fractol = F_BURNIN;
		init_env3(e);
	}
	if (keycode == K_5)
	{
		e->fractol = F_TREE;
		init_env5(e);
	}
}

static	int		key_hook2(int keycode, t_env *e)
{
	if (keycode == K_F16)
		e->keyf = (e->keyf == 0 ? 1 : 0);
	if (keycode == K_I)
		e->keybd = 7;
	if (keycode == K_U)
		e->keybd = 8;
	if (keycode == K_SP)
		e->mouse = (e->mouse == 0 ? 1 : 0);
	if (keycode == K_C1)
		e->keycol = 1;
	if (keycode == K_C2)
		e->keycol = 2;
	if (keycode == K_C3)
		e->keycol = 3;
	if (keycode == K_C4)
		e->keycol = 4;
	if (keycode == K_C5)
		e->keycol = 5;
	if (keycode == K_C6)
		e->keycol = 6;
	key_change_fractal(keycode, e);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		key_quit(e);
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
	key_hook3(keycode, e);
	key_hook2(keycode, e);
	return (0);
}
