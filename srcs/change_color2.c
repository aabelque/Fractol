/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:43:33 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/10 17:41:03 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color			color_yy(void)
{
	t_color				red;

	red.r = 255;
	red.g = 140;
	red.b = 50;
	red.a = 0;
	return (red);
}

void					change_color6(t_env *e)
{
	e->ptf.ptcol1 = color_bc;
	e->ptf.ptcol2 = color_yy;
	e->ptf.ptcol3 = color_bc;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}
