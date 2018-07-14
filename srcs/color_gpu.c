/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gpu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:09:43 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/14 09:49:30 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_color_gpu(t_fractal c)
{
	c.color[0][0] = 0x7F1637;
	c.color[0][1] = 0x047878;
	c.color[0][2] = 0xFFB733;
	c.color[0][3] = 0xF57336;
	c.color[0][4] = 0xC22121;
	c.color[0][5] = 0xFFB733;

	c.color[1][0] = 0x091D36;
	c.color[1][1] = 0x3A4E7A;
	c.color[1][2] = 0x5E83BA;
	c.color[1][3] = 0xC2D2E9;
	c.color[1][4] = 0xF1F1F0;
	c.color[1][5] = 0x3A4E7A;

	c.color[2][0] = 0xe56b6b;
	c.color[2][1] = 0xdd5151;
	c.color[2][2] = 0xba3404;
	c.color[2][3] = 0xab1f1f;
	c.color[2][4] = 0x940808;
	c.color[2][5] = 0xba3404;

	c.color[3][0] = 0xfdcf58;
	c.color[3][1] = 0xf07f13;
	c.color[3][2] = 0xf27d0c;
	c.color[3][3] = 0x800909;
	c.color[3][4] = 0xf07f13;
	c.color[3][5] = 0xfdcf58;

	c.color[4][0] = 0xf0e5c4;
	c.color[4][1] = 0xead8a1;
	c.color[4][2] = 0xe1c782;
	c.color[4][3] = 0xd2b25b;
	c.color[4][4] = 0xc3983a;
	c.color[4][5] = 0xe1c782;
}
