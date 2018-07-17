/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 11:31:51 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 10:28:45 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_col(t_fractal *c)
{
	c->sc = 0;
	c->col_style = 0;
	c->clr = 128;
	c->clr2 = 127;
	c->r_freq = 0.33;
	c->g_freq = 0.33;
	c->b_freq = 0.33;
	c->r_ph = 0.00;
	c->g_ph = (2 * M_PI) / 3;
	c->b_ph = (4 * M_PI) / 3;
	c->psych = 0;
}

void	col_pal(t_fractal *c)
{
	c->col_style = (c->col_style + 1) % 4;
	if (c->col_style == 0)
	{
		c->r_freq = 0.33;
		c->g_freq = 0.33;
		c->b_freq = 31.33;
	}
	if (c->col_style == 1)
	{
		c->r_freq = 31.33;
		c->g_freq = 0.33;
		c->b_freq = 0.00;
	}
	if (c->col_style == 2)
	{
		c->r_freq = 0.33;
		c->g_freq = 30.00;
		c->b_freq = 0.33;
	}
	if (c->col_style == 3)
	{
		c->r_freq = 0.00;
		c->g_freq = 0.33;
		c->b_freq = 0.33;
	}
}

void	color_random(t_fractal *c)
{
	c->r_freq = rand() % 10;
	c->g_freq = rand() % 10;
	c->b_freq = rand() % 10;
}

void	psych_col_rand(t_fractal *c)
{
	c->r_ph = rand() % 20;
	c->g_ph = rand() % 20;
	c->b_ph = rand() % 20;
}

int		ch_col(t_fractal *c, float iter)
{
	int		r;
	int		g;
	int		b;

	if (iter >= c->i_max)
		return (0);
	else
	{
		r = sin(fmod(c->r_freq * iter + c->r_ph, 2 * M_PI))
			* c->clr2 + c->clr;
		g = sin(fmod(c->g_freq * iter + c->g_ph, 2 * M_PI))
			* c->clr2 + c->clr;
		b = sin(fmod(c->b_freq * iter + c->b_ph, 2 * M_PI))
			* c->clr2 + c->clr;
		return (r << 16 | g << 8 | b);
	}
}
