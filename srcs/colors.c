/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:11:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/24 15:36:23 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		colortohex(t_color color)
{
	return ((unsigned int)(color.r << 16 | color.g << 8 || color.b));
}

unsigned int		set_color(int a, t_env *e)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	//unsigned char	al;
	
	if (a >= I_MAX)
		return (e->colorm);
	r = (a * 5) * e->colorv;
	g = (a * 2) * e->colorv;
	b = (a * 1) * e->colorv;
	//al = 255;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

t_color			color_r(void)
{
	t_color		red;

	red.r = 255;
	red.g = 0;
	red.b = 0;
	red.a = 0;
	return (red);
}

t_color			color_g(void)
{
	t_color		green;

	green.r = 0;
	green.g = 255;
	green.b = 0;
	green.a = 0;
	return (green);
}

t_color			color_bl(void)
{
	t_color		black;
	black.r = 200;
	black.g = 200;
	black.b = 200;
	black.a = 0;
	return (black);
}

t_color			color_b(void)
{
	t_color		blue;
	blue.r = 0;
	blue.g = 0;
	blue.b = 255;
	blue.a = 0;
	return (blue);
}

t_color			color_bc(void)
{
	t_color		blue;
	blue.r = 0;
	blue.g = 0;
	blue.b = 0;
	blue.a = 0;
	return (blue);
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

	//i /= 2;
	if (i < 0.5)
	{
		new_color.r = a.r + (b.r - a.r) * i * 2;
		new_color.g = a.g + (b.g - a.g) * i * 2;
		new_color.b = a.b + (b.b - a.b) * i * 2;
		new_color.a = a.a + (b.a - a.a) * i * 2;
	}
	/*else if (i < 0.6)
	{
		new_color.r = b.r + (c.r - b.r) * i;
		new_color.g = b.g + (c.g - b.g) * i;
		new_color.b = b.b + (c.b - b.b) * i;
		new_color.a = b.a + (c.a - b.a) * i;
	}
	if (i <= 0.7)
	{
		new_color.r = a.r + (c.r - b.r) * i;
		new_color.g = a.g + (b.g - c.g) * i;
		new_color.b = b.b + (c.b - a.b) * i;
		new_color.a = b.a + (a.a - c.a) * i;
	}*/
	else
	{
		new_color.r = b.r + (c.r - b.r) * (i - 0.5) * 2;
		new_color.g = b.g + (c.g - b.g) * (i - 0.5) * 2;
		new_color.b = b.b + (c.b - b.b) * (i - 0.5) * 2;
		new_color.a = b.a + (c.a - b.a) * (i - 0.5) * 2;
	}
	return (new_color);
}
