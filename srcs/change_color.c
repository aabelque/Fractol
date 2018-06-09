/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:27:32 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/09 14:07:12 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color(t_env *e)
{
	e->ptf.ptcol1 = color_bc;
	e->ptf.ptcol2 = color_r;
	e->ptf.ptcol3 = color_bl;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}

void		change_color2(t_env *e)
{
	e->ptf.ptcol1 = color_bl;
	e->ptf.ptcol2 = color_r;
	e->ptf.ptcol3 = color_b;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}

void		change_color3(t_env *e)
{
	e->ptf.ptcol1 = color_bc;
	e->ptf.ptcol2 = color_g;
	e->ptf.ptcol3 = color_bc;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}

void		change_color4(t_env *e)
{
	e->ptf.ptcol1 = color_bl;
	e->ptf.ptcol2 = color_y;
	e->ptf.ptcol3 = color_bl;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}

void		change_color5(t_env *e)
{
	e->ptf.ptcol1 = color_bc;
	e->ptf.ptcol2 = color_y;
	e->ptf.ptcol3 = color_bl;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}
