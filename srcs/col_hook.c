/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:00:49 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 12:47:58 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		col_hook(t_env *e)
{
	if (e->fra.psych == 1 && e->device == 2)
	{
		e->fra.r_ph = (e->fra.r_ph > 2 * M_PI) ?
		fmod(e->fra.r_ph, 2 * M_PI) : e->fra.r_ph + 0.015;
		e->fra.g_ph = (e->fra.g_ph > 2 * M_PI) ?
		fmod(e->fra.g_ph, 2 * M_PI) : e->fra.g_ph + 0.015;
		e->fra.b_ph = (e->fra.b_ph > 2 * M_PI) ?
		fmod(e->fra.b_ph, 2 * M_PI) : e->fra.b_ph + 0.015;
	}
	if (e->fra.psych == 1 && e->device != 2)
	{
		e->fra.r_ph = (e->fra.r_ph > 2 * M_PI) ?
		fmod(e->fra.r_ph, 2 * M_PI) : e->fra.r_ph + 0.07;
		e->fra.g_ph = (e->fra.g_ph > 2 * M_PI) ?
		fmod(e->fra.g_ph, 2 * M_PI) : e->fra.g_ph + 0.07;
		e->fra.b_ph = (e->fra.b_ph > 2 * M_PI) ?
		fmod(e->fra.b_ph, 2 * M_PI) : e->fra.b_ph + 0.07;
	}
	return (0);
}
