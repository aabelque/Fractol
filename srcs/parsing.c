/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:28:34 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/24 18:37:29 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			parsing_arg2(char *str, t_env *e)
{
	if (ft_strequ(str, "Burningship"))
	{
		e->fractol = 4;
		init_env3(e);
		return (1);
	}
	else
		return (-1);
	return (0);
}

int			parsing_arg(char *str, t_env *e)
{
	if (ft_strequ(str, "Mandelbrot"))
	{
		e->fractol = 1;
		init_env(e);
		return (1);
	}
	else if (ft_strequ(str, "Julia"))
	{
		init_env2(e);
		e->fractol = 2;
		return (1);
	}
	else if (ft_strequ(str, "Mandelbrot3"))
	{
		init_env(e);
		e->fractol = 3;
		return (1);
	}
	else
		return (-1);
	return (0);
}
