/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:28:34 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/26 12:33:24 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			parsing_arg2(char *str, char *s, t_env *e)
{
	e->device = (ft_strequ(str, "-cpu") ? 1 : 0);
	if (e->device == 0)
		e->device = (ft_strequ(str, "-gpu") ? 2 : 0);
	if (ft_strequ(s, "Burningship"))
	{
		e->fractol = F_BURNIN;
		init_env3(e);
		return (1);
	}
	if (ft_strequ(s, "Tree"))
	{
		e->fractol = F_TREE;
		init_env5(e);
		return (1);
	}
	if (ft_strequ(s, "Sponge"))
	{
		e->fractol = F_SPONGE;
		init_env4(e);
		return (1);
	}
	else
		return (-1);
	return (0);
}

int			parsing_arg(char *str, char *s, t_env *e)
{
	e->device = (ft_strequ(str, "-cpu") ? 1 : 0);
	if (e->device == 0)
		e->device = (ft_strequ(str, "-gpu") ? 2 : 0);
	if (ft_strequ(s, "Mandelbrot"))
	{
		e->fractol = F_MANDEL;
		init_env(e);
		return (1);
	}
	else if (ft_strequ(s, "Julia"))
	{
		e->fractol = F_JULIA;
		init_env2(e, 0.285, 0.01);
		return (1);
	}
	else if (ft_strequ(s, "Multibrot"))
	{
		e->fractol = F_MULTI;
		init_env(e);
		return (1);
	}
	else
		return (-1);
	return (0);
}
