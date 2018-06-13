/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:28:34 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/13 11:35:17 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			parsing_arg2(char *str, t_env *e)
{
	if (ft_strequ(str, "Burningship"))
	{
		e->fractol = F_BURNIN;
		init_env3(e);
		return (1);
	}
	if (ft_strequ(str, "Tree"))
	{
		e->fractol = F_TREE;
		init_env5(e);
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
		e->fractol = F_MANDEL;
		init_env(e);
		return (1);
	}
	else if (ft_strequ(str, "Julia"))
	{
		e->fractol = F_JULIA;
		init_env2(e, 0.285, 0.01);
		return (1);
	}
	else if (ft_strequ(str, "Multibrot"))
	{
		e->fractol = F_MULTI;
		init_env(e);
		return (1);
	}
	else
		return (-1);
	return (0);
}
