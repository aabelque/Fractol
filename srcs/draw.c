/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:30:09 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/05 12:49:41 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		redraw(t_env *e)
{
	if (e->fractol == 1)
		mandelbrot(e);
	else if (e->fractol == 2)
		julia(e);
	else if (e->fractol == 3)
		mandelbrot3(e);
	else if (e->fractol == 4)
		burningship(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
}

void		set_pxl(t_env *e, int x, int y, t_color color)
{
	int		pxl;

	pxl = (x * 4) + (y * e->img.s_line);
	e->img.addr[pxl] = color.b;
	e->img.addr[++pxl] = color.g;
	e->img.addr[++pxl] = color.r;
	e->img.addr[++pxl] = color.a;
}
