/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:27:32 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/08 18:32:16 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color(t_env *e)
{
	dprintf(2, "test");
	e->ptf.ptcol1 = color_r;
	e->ptf.ptcol2 = color_y;
	e->ptf.ptcol3 = color_b;
	e->ptf.ptcol4 = color_bc;
	e->keycol = 0;
}
