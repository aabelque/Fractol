/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:18:11 by aabelque          #+#    #+#             */
/*   Updated: 2018/05/23 11:38:43 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_env	*e;
	int		ret;

	e = NULL;
	if (ac != 2)
		ft_error("Usage: ./fractol <Fractal's name>");
	if (!(e = ft_memalloc(sizeof(t_env))))
		ft_malloc_error(e);
	if ((ret = parsing_arg(av[1], e)) == -1)
	{
		clean(e);
		ft_usage();
		exit(0);
	}
	init_mlx(e);
	mlx_loop(e->mlx);
	return (0);
}
