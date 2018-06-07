/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:24:34 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/07 14:18:22 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_release_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == M_LC)
		e->mouse = 0;
	return (0);
}

int		mouse_motion_hook(int x, int y, t_env *e)
{
	if (e->mouse == 1)
		julia_move(e, x, y);
	return (0);
}
