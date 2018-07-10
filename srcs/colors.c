/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:11:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/10 12:40:38 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_color(t_env *e)
{
	e->ptf.ptcol1 = color_b;
	e->ptf.ptcol2 = color_bl;
	e->ptf.ptcol3 = color_r;
	e->ptf.ptcol4 = color_bc;
}

t_color			color_y(void)
{
	t_color		yel;

	yel.r = 0;
	yel.g = 125;
	yel.b = 200;
	yel.a = 0;
	return (yel);
}

t_color			interpol_color(t_color a, t_color b, double i)
{
	t_color		new_color;

	new_color.r = a.r + (b.r - a.r) * i;
	new_color.g = a.g + (b.g - a.g) * i;
	new_color.b = a.b + (b.b - a.b) * i;
	new_color.a = a.a + (b.a - a.a) * i;
	return (new_color);
}

t_color			interpol_color2(t_color a, t_color b, t_color c, double i)
{
	t_color		new_color;

	i = fmax(i, 0);
	if (i <= 0.5)
	{
		new_color.r = a.r + (b.r - a.r) * i * 2;
		new_color.g = a.g + (b.g - a.g) * i * 2;
		new_color.b = a.b + (b.b - a.b) * i * 2;
		new_color.a = a.a + (b.a - a.a) * i * 2;
	}
	else
	{
		new_color.r = b.r + (c.r - b.r) * (i - 0.5) * 2;
		new_color.g = b.g + (c.g - b.g) * (i - 0.5) * 2;
		new_color.b = b.b + (c.b - b.b) * (i - 0.5) * 2;
		new_color.a = b.a + (c.a - b.a) * (i - 0.5) * 2;
	}
	return (new_color);
}
