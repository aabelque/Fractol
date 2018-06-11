/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:34:01 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/11 18:32:47 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			move_up(t_env *e)
{
	long double	sh;

	sh = 0.05 * (e->fra.x2 - e->fra.x1);
	e->fra.y1 += sh;
	e->fra.y2 += sh;
}

void			move_do(t_env *e)
{
	long double	sh;

	sh = 0.05 * (e->fra.x2 - e->fra.x1);
	e->fra.y1 -= sh;
	e->fra.y2 -= sh;
}

void			move_r(t_env *e)
{
	long double	sh;

	sh = 0.05 * (e->fra.x2 - e->fra.x1);
	e->fra.x1 -= sh;
	e->fra.x2 -= sh;
}

void			move_l(t_env *e)
{
	long double	sh;

	sh = 0.05 * (e->fra.x2 - e->fra.x1);
	e->fra.x1 += sh;
	e->fra.x2 += sh;
}
