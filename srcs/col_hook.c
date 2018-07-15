/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:00:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/15 14:39:35 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		col_hook(t_fractal *c)
{
	if (c->psych == 1)
	{
		c->r_ph = (c->r_ph > 2 * M_PI) ?
		fmod(c->r_ph, 2 * M_PI) : c->r_ph + 0.05;
		c->g_ph = (c->g_ph > 2 * M_PI) ?
		fmod(c->g_ph, 2 * M_PI) : c->g_ph + 0.05;
		c->b_ph = (c->b_ph > 2 * M_PI) ?
		fmod(c->b_ph, 2 * M_PI) : c->b_ph + 0.05;
	}
	return (0);
}
