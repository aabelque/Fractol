/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:48:25 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/09 19:01:07 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int				key_hook3(int keycode, t_env *e)
{
	if (keycode == K_C0)
	{
		if (e->smth == 5000.0 && e->fractol != F_MULTI)
			e->smth = 2.0;
		else if (e->smth == 5000.0 && e->fractol == F_MULTI)
			e->smth = e->fra.n;
		else
			e->smth = 5000.0;
	}
	if (keycode == K_C7)
	{
		e->fractol = F_TRI;
		init_env(e);
	}
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
		(e->fractol != F_TREE) ? (e->fra.i_max += 2) : (e->fra.i_max2 += 0.1);
		(e->fractol != F_TREE) ? (void)e : (e->fra.zoom -= 0.01);
	}
	if (e->keybd == 8)
	{
		(e->fractol != F_TREE) ? (e->fra.i_max -= 2) : (e->fra.i_max2 -= 0.1);
		(e->fractol != F_TREE) ? (void)e : (e->fra.zoom += 0.01);
	}
	key_press2(e);
	return (0);
}
