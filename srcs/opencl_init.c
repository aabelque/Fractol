/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:30:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/17 18:34:00 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				set_opencl_env(t_opencl *opcl)
{
	opcl->dev_type = CL_DEVICE_TYPE_GPU;
	opcl->err = 0;
	opcl->local = 0;
	opcl->platform_id = NULL;
	opcl->device_id = 0;
	opcl->context = NULL;
	opcl->commands = NULL;
	opcl->program = NULL;
	opcl->kernel_src = NULL;
	opcl->input = NULL;
	opcl->output = NULL;
	opcl->imgxy[0] = X_WIN;
	opcl->imgxy[1] = Y_WIN;
	opcl->deg = 0;
	ft_bzero(opcl->kernel, sizeof(char) * 5);
}

void				create_kernel(cl_program program, cl_kernel *kernel,
		const char *func)
{
	cl_int			err;

	if (!(*kernel = clCreateKernel(program, func, &err)))
	{
		ft_putendl("Error: Failed to create kernel");
		exit(EXIT_FAILURE);
	}
}

char				*get_kernel_source(char *file)
{
	char			*kernel_src;
	struct stat		stats;
	int				fd;

	if (stat(file, &stats) == -1)
	{
		ft_putendl("Error: kernel source not found");
		exit(EXIT_FAILURE);
	}
	if (!(fd = open(file, O_RDONLY)))
	{
		ft_putendl("Error: fail to load kernel source");
		exit(EXIT_FAILURE);
	}
	kernel_src = ft_memalloc(stats.st_size);
	read(fd, kernel_src, stats.st_size);
	close(fd);
	return (kernel_src);
}

void				create_prog(t_opencl *opcl)
{
	cl_int			error;

	opcl->kernel_src = get_kernel_source("./srcs/fractal_gpu.cl");
	if (!(opcl->program = clCreateProgramWithSource(opcl->context, 1,
					(const char **)&opcl->kernel_src, NULL, &opcl->err)))
	{
		ft_putendl("Error: Failed to create program with source");
		exit(EXIT_FAILURE);
	}
	error = clBuildProgram(opcl->program, 1, &opcl->device_id,
				NULL, NULL, NULL);
	error_gpu(opcl);
	free((void *)opcl->kernel_src);
}

void				opencl_init(t_opencl *opcl)
{
	if (clGetPlatformIDs(1, &opcl->platform_id, NULL) != CL_SUCCESS)
	{
		ft_putendl("Error: Failed to get a platformID");
		exit(EXIT_FAILURE);
	}
	if (clGetDeviceIDs(opcl->platform_id, opcl->dev_type, 1,
			&opcl->device_id, &opcl->num_dev) != CL_SUCCESS)
	{
		ft_putendl("Error: Failed to create deviceID group");
		exit(EXIT_FAILURE);
	}
	if (!(opcl->context = clCreateContext(0, 1, &opcl->device_id, NULL, NULL,
			&opcl->err)))
	{
		ft_putendl("Error: Failed to create a context");
		exit(EXIT_FAILURE);
	}
	if (!(opcl->commands = clCreateCommandQueue(opcl->context, opcl->device_id,
			0, &opcl->err)))
	{
		ft_putendl("Error: Failed to create command queue");
		exit(EXIT_FAILURE);
	}
	opencl_init2(opcl);
}
