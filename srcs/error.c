/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:20:10 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/12 15:59:10 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void		ft_malloc_error(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img.img = NULL;
	ft_putendl("malloc error");
	exit(0);
}

void		ft_usage(void)
{
	ft_putstr("\
____________________________________\n\
Usage: ./fractol <Fractal's name>\n\
\n\
Fractal's name:\n\
	| Mandelbrot   |\n\
	| Mandelbrot2  |\n\
	| Julia        |\n\
	| Burningship  |\n\
	| Tree 		   |\n\
____________________________________\n\
");
}
