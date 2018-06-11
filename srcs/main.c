/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:18:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/10 15:52:40 by aabelque         ###   ########.fr       */
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
Scale:\n\
	Widen: +\n\
	Narrow: -\n\
__________________________\n\
");
}

int				main(int ac, char **av)
{
	t_env		*e;

	e = NULL;
	if (ac != 2)
		ft_error("Usage: ./fractol <Fractal's name>");
	if (!(e = ft_memalloc(sizeof(t_env))))
		ft_malloc_error(e);
	if (parsing_arg(av[1], e) == -1 && parsing_arg2(av[1], e) == -1)
	{
		clean(e);
		ft_usage();
		exit(EXIT_FAILURE);
	}
	init_funct(e);
	init_color(e);
	init_mlx(e);
	display_ctrl();
	mlx_loop(e->mlx);
	return (0);
}
