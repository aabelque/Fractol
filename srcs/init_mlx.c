/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:09:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/11 18:50:41 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	clean(e);
	exit(EXIT_SUCCESS);
}

void	init_funct(t_env *e)
{
	e->func[F_MANDEL] = &mandelbrot;
	e->func[F_JULIA] = &julia;
	e->func[F_MANDEL2] = &mandelbrot3;
	e->func[F_BURNIN] = &burningship;
	e->func[F_BUDDHA] = &launch_bb;
}

int		loop_hook(t_env *e)
{
	key_press(e);
	if (e->fractol != F_TREE)
		send_thread(e);
	else
		send_tree(e, e->fra.i_max);
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
	mlx_hook(e->win, 4, 0, mouse_hook, e);
	mlx_hook(e->win, 6, 0, mouse_motion_hook, e);
	mlx_hook(e->win, 2, 0, key_hook, e);
	mlx_hook(e->win, 17, 0, key_quit, e);
	mlx_hook(e->win, 3, 0, key_release_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	return (0);
}
