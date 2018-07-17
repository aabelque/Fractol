/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:07:23 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 17:10:33 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	opencl_init2(t_opencl *opcl)
{
	opcl->img_s = X_WIN * Y_WIN;
	opcl->bufhst = (int *)ft_memalloc(opcl->img_s * sizeof(int));
	opcl->input = clCreateBuffer(opcl->context, CL_MEM_READ_ONLY,
			sizeof(t_fractal), NULL, NULL);
	opcl->output = clCreateBuffer(opcl->context, CL_MEM_WRITE_ONLY,
			sizeof(int) * opcl->img_s, NULL, NULL);
	create_prog(opcl);
	create_kernel(opcl->program, &opcl->kernel[0], "mandelbrot_gpu");
	create_kernel(opcl->program, &opcl->kernel[1], "julia_gpu");
	create_kernel(opcl->program, &opcl->kernel[2], "multibrot_gpu");
	create_kernel(opcl->program, &opcl->kernel[3], "burningship_gpu");
	create_kernel(opcl->program, &opcl->kernel[4], "tricorn_gpu");
}
