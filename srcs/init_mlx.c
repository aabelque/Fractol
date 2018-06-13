/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:09:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/13 17:43:01 by aabelque         ###   ########.fr       */
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
	e->func[F_MULTI] = &multibrot;
	e->func[F_BURNIN] = &burningship;
	e->func[F_SPONGE] = &sponge;
}

int		loop_hook(t_env *e)
{
	key_press(e);
	(e->fractol != F_TREE) ? (send_thread(e)) : (send_tree(e, e->fra.i_max2));
	if (mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0) == -1)
		ft_error("fail to put image");
	mlx_string_put(e->mlx, e->win, X_WIN - X_WIN, 1, 0xffffff,
				"Press F16 to show Controls");
	if (e->keyf == 1)
	{
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 1, 0xffffff,
				"Change Fractal: Keybd 1 -> 6");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 20, 0xffffff,
				"Color: Num Keypad 1 -> 6");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 39, 0xffffff,
				"Smooth color: Num Keypad 0");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 58, 0xffffff,
				"Iteration: I, U");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 77, 0xffffff,
				"Multibrot: Change Form P, O");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 96, 0xffffff,
				"Zoom: +, -, mouse scroll");
		mlx_string_put(e->mlx, e->win, X_WIN - 300, 115, 0xffffff,
				"Move: Arrow");
	}
	ft_bzero(e->img.addr, sizeof(int) * X_WIN * Y_WIN);
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
