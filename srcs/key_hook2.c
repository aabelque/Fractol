/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:48:25 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/07 14:19:30 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_release_hook(int keycode, t_env *e)
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

int		key_press(t_env *e)
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
		e->fra.i_max += 2;
	if (e->keybd == 8)
		e->fra.i_max -= 2;
	return (0);
}
