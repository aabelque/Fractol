/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:42:55 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/09 14:08:18 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	green.r = 125;
	green.g = 255;
	green.b = 125;
	green.a = 0;
	return (green);
}

t_color			color_bl(void)
{
	t_color		white;

	white.r = 200;
	white.g = 200;
	white.b = 200;
	white.a = 0;
	return (white);
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
	t_color		black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 0;
	return (black);
}
