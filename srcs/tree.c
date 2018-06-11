/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:54:26 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/11 18:17:20 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	put_tree(t_env *e, t_tree start, t_tree end, int color)
{
	long double	dd;
	long double	x;
	long double	y;
	long double	dx;
	long double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		set_pxl2(e->img, x, y, color);
		x += dx;
		y += dy;
	}
}

void			tree(t_env *e, t_tree start, long double angle, int iter)
{
	t_tree		end;
	int			color;

	if (iter > 0)
	{
		end.x = start.x + (cos(angle) * iter * 6) * e->fra.zoom;
		end.y = start.y + (sin(angle) * iter * 9) * e->fra.zoom;
		color = ((50 + e->fra.r * iter) << 16) + ((e->fra.g * iter) << 8)
			+ (155 - e->fra.b * iter);
		put_tree(e, start, end, color);
		tree(e, end, angle - (M_PI / 8 * e->fra.size_tree * 2), iter - 1);
		tree(e, end, angle + (M_PI / 8 * e->fra.size_tree2 * 2), iter - 1);
	}
}

void			send_tree(t_env *e, int iter)
{
	t_tree		start;

	start.x = X_WIN / 2 - (e->fra.x1 * (e->fra.zoom / 4.1));
	start.y = Y_WIN - 20 + (e->fra.x2 * (e->fra.zoom / 1.2));
	tree(e, start, -(M_PI / 2), iter);
}

void			tree_move(t_env *e, int x, int y)
{
	e->fra.size_tree = (long double)x / X_WIN;
	e->fra.size_tree2 = (long double)y / Y_WIN;
}
