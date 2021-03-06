/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:48:25 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 16:53:34 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static	int		key_hook4(int keycode, t_env *e)
{
	if (keycode == K_W)
		e->fra.sc = (e->fra.sc == 0 ? 1 : 0);
	if (keycode == K_D)
		e->fra.psych = (e->fra.psych == 0 ? 1 : 0);
	if (keycode == K_A)
		col_pal(&e->fra);
	if (keycode == K_CC)
		color_random(&e->fra);
	if (keycode == K_S)
		psych_col_rand(&e->fra);
	return (0);
}

int				key_hook3(int keycode, t_env *e)
{
	if (keycode == K_C0)
	{
		if (e->fra.smth == 5000.0 && e->fractol != F_MULTI)
			e->fra.smth = 2.0;
		else if (e->fra.smth == 5000.0 && e->fractol == F_MULTI)
			e->fra.smth = e->fra.n;
		else
			e->fra.smth = 5000.0;
	}
	if (keycode == K_5)
	{
		e->fractol = F_TRI;
		init_env(e);
	}
	key_hook4(keycode, e);
	return (0);
}

static	int		key_press2(t_env *e)
{
	if (e->keycol == 1)
		change_color(e);
	if (e->keycol == 2)
		change_color2(e);
	if (e->keycol == 3)
		change_color3(e);
	if (e->keycol == 4)
		change_color4(e);
	if (e->keycol == 5)
		change_color5(e);
	if (e->keycol == 6)
		change_color6(e);
	return (0);
}

int				key_release_hook(int keycode, t_env *e)
{
	if (keycode == K_PLUS)
		e->keybd = 0;
	if (keycode == K_LESS)
		e->keybd = 0;
	if (keycode == K_UP)
		e->keybd = 0;
	if (keycode == K_DOWN)
		e->keybd = 0;
	if (keycode == K_RIGHT)
		e->keybd = 0;
	if (keycode == K_LEFT)
		e->keybd = 0;
	if (keycode == K_I)
		e->keybd = 0;
	if (keycode == K_U)
		e->keybd = 0;
	return (0);
}

int				key_press(t_env *e)
{
	if (e->keybd == 1)
		zoom_upk(e);
	if (e->keybd == 2)
		zoom_dok(e);
	if (e->keybd == 3)
		move_up(e);
	if (e->keybd == 4)
		move_do(e);
	if (e->keybd == 5)
		move_r(e);
	if (e->keybd == 6)
		move_l(e);
	if (e->keybd == 7)
	{
		(e->fractol != F_TREE) ? (e->fra.i_max += 5) : (e->fra.i_max2 += 0.1);
		(e->fractol != F_TREE) ? (void)e : (e->fra.zoom -= 0.01);
	}
	if (e->keybd == 8)
	{
		(e->fractol != F_TREE) ? (e->fra.i_max -= 5) : (e->fra.i_max2 -= 0.1);
		(e->fractol != F_TREE) ? (void)e : (e->fra.zoom += 0.01);
	}
	key_press2(e);
	return (0);
}
