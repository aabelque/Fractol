/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:09:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/23 17:46:11 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	redraw(e);
	return (0);
}

int		loop_hook(t_env *e)
{
	if (e->fractol == 1)
		mandelbrot(e);
	else if (e->fractol == 2)
		julia(e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
	return (0);
}

int		init_mlx(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	e->win = mlx_new_window(e->mlx, X_WIN, Y_WIN, "FRACTOL");
	e->img.img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	e->img.addr = mlx_get_data_addr(e->img.img, &(e->img.bpp),
			&(e->img.s_line), &(e->img.endian));
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	return (0);
}
