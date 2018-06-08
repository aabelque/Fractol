/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:30:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/08 15:51:53 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_pxl(t_img *e, int x, int y, t_color color)
{
	int		pxl;

	pxl = (x * 4) + (y * e->s_line);
	e->addr[pxl] = color.b;
	e->addr[++pxl] = color.g;
	e->addr[++pxl] = color.r;
	e->addr[++pxl] = color.a;
}
