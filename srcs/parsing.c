/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:28:34 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/23 13:15:51 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else
		return (-1);
	return (0);
}
