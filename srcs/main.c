/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:18:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/15 13:03:59 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	display_ctrl(void)
{
	ft_putstr("\
__________________________\n\
CONTROLS:\n\
Quit:\n\
	KEY: ESC\n\
\n\
Move:\n\
	Left: Left Arrow\n\
	Right: Right Arrow\n\
	Up: Up Arrow\n\
	Down: Down Arrow\n\
\n\
Zoom:\n\
	Widen: +\n\
	Narrow: -\n\
	Scroll: Up Down\n\
\n\
Iteration:\n\
	Inc: I\n\
	Decr: U\n\
__________________________\n\
");
}

static void		m_help(t_env *e)
{
	if (e->device == 0)
	{
		clean(e);
		ft_usage();
		exit(EXIT_FAILURE);
	}
	if (e->device == 1)
		init_funct(e);
	else
	{
		set_opencl_env(&e->opcl);
		opencl_init(&e->opcl, e);
	}
}

int				main(int ac, char **av)
{
	t_env		*e;

	e = NULL;
	if (ac != 3)
		ft_error("Usage: ./fractol [-cpu || -gpu] <Fractal's name>");
	if (!(e = ft_memalloc(sizeof(t_env))))
		ft_malloc_error(e);
	if (parsing_arg(av[1], av[2], e) == -1 &&
			parsing_arg2(av[1], av[2], e) == -1)
	{
		clean(e);
		ft_usage();
		exit(EXIT_FAILURE);
	}
	setup_col(&e->fra);
	init_color(e);
	init_mlx(e);
	m_help(e);
	display_ctrl();
	mlx_loop(e->mlx);
	return (0);
}
