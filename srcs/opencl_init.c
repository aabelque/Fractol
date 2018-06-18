/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:30:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/18 17:04:26 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_opencl_env(t_opencl *opcl)
{
	opcl->dev_type = CL_DEVICE_TYPE_GPU;
	opcl->err = NULL;
	opcl->global = NULL;
	opcl->local = NULL;
	opcl->platform_id = NULL;
	opcl->device_id = NULL;
	opcl->context = NULL;
	opcl->commands = NULL;
	opcl->program = NULL;
	opcl->kernel = NULL;
	//opcl->kernel_src = ?;
}

void		create_kernel(cl_program program, cl_kernel *kernel, const char *func)
{
	
}

void		create_prog(t_opencl *opcl)
{
	if (!(opcl->program = clCreateProgramWithSource(opcl->context, 1,
					(const char **)&opcl->kernel_src, NULL, &opcl->err)))
	{
		ft_putendl("Error: Fail to create program with source");
		exit(EXIT_FAILURE);
	}
}

void			opencl_init(t_opencl *opcl)
{
	if (clGetPlatfromIDs(1, &opcl->platform_id, NULL) != CL_SUCCESS)
	{
		ft_putendl("Error: Fail to get a platformID");
		exit(EXIT_FAILURE);
	}
	if (clGetDeviceIDs(opcl->platform_id, opcl->dev_type, 1,
			&opcl->device_id, NULL) != CL_SUCCESS)
	{
		ft_putendl("Error: Fail to create deviceID group");
		exit(EXIT_FAILURE);
	}
	if (!(opcl->context = clCreateContext(0, 1, &opcl->device_id, NULL, NULL,
			&opcl->err)))
	{
		ft_putendl("Error: Fail to create a context");
		exit(EXIT_FAILURE);
	}
	if (!(opcl->commands = clCreateCommandQueue(opcl->context, opcl->device_id,
			0, &opcl->err)))
	{
		ft_putendl("Error: Fail to create command queue");
		exit(EXIT_FAILURE);
	}
}
