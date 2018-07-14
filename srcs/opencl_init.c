/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:30:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/07/14 16:31:44 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_opencl_env(t_opencl *opcl)
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
}

void		create_kernel(cl_program program, cl_kernel *kernel, const char *func)
{
	cl_int	err;
	if (!(*kernel = clCreateKernel(program, func, &err)))
	{
		ft_putendl("Error: Failed to create kernel");
		exit(EXIT_FAILURE);
	}
}

char		*get_kernel_source(char *file)
{
	char	*kernel_src;
	struct stat		stats;
	int				fd;

	if (lstat(file, &stats) == -1)
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

void		create_prog(t_opencl *opcl)
{
	opcl->kernel_src = get_kernel_source("srcs/mandelbrot_gpu.cl"); 
	if (!(opcl->program = clCreateProgramWithSource(opcl->context, 1,
					(const char **)&opcl->kernel_src, NULL, &opcl->err)))
	{
		ft_putendl("Error: Failed to create program with source");
		exit(EXIT_FAILURE);
	}
	cl_int	error;
	error = clBuildProgram(opcl->program, 1, &opcl->device_id,
				"-I./include", NULL, NULL);
	if (clBuildProgram(opcl->program, 1, &opcl->device_id,
				"-I./include", NULL, NULL) != CL_SUCCESS)
	{
		char *errbuf;
		cl_int coderr;
		size_t errlog;
		coderr = clGetProgramBuildInfo(opcl->program, opcl->device_id,
				CL_PROGRAM_BUILD_LOG, 0, NULL, &errlog);
		errbuf = ft_memalloc(sizeof(errlog));
		coderr = clGetProgramBuildInfo(opcl->program, opcl->device_id,
				CL_PROGRAM_BUILD_LOG, errlog, errbuf, NULL);
//		fprintf(stderr,"Build log: \n%s\n", errbuf);
		ft_putendl("Error: Failed to build program");
		ft_putendl(errbuf);
		exit(EXIT_FAILURE);
	}
	free((void *)opcl->kernel_src);
}

void			opencl_init(t_opencl *opcl, t_env *e)
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
	(void)e;
	opcl->img_s = X_WIN * Y_WIN;
	opcl->bufhst = (int *)ft_memalloc(opcl->img_s * sizeof(int)); 
	opcl->input = clCreateBuffer(opcl->context, CL_MEM_READ_ONLY,
			sizeof(t_fractal), NULL, NULL);
	opcl->output = clCreateBuffer(opcl->context, CL_MEM_WRITE_ONLY,
			sizeof(int) * opcl->img_s, NULL, NULL);
	create_prog(opcl);
	create_kernel(opcl->program, &opcl->kernel[0], "mandelbrot_gpu");
//	create_kernel(opcl->program, opcl->kernel[1], "julia_gpu");
//	create_kernel(opcl->program, opcl->kernel[2], "multibrot_gpu");
//	create_kernel(opcl->program, opcl->kernel[3], "burningship_gpu");

}

void			opencl_draw(t_opencl *opcl, t_env *e, float deg)
{
	size_t		i;

	opcl->err = 0;
	opcl->err = clEnqueueWriteBuffer(opcl->commands, opcl->input, CL_TRUE, 0,
			sizeof(t_fractal), (void *)&e->fra, 0, NULL, NULL);
	opcl->err |= clSetKernelArg(*opcl->kernel, 0, sizeof(cl_mem), &opcl->output);
	opcl->err |= clSetKernelArg(*opcl->kernel, 1, sizeof(cl_mem), &opcl->input);
	opcl->err = clEnqueueNDRangeKernel(opcl->commands, *opcl->kernel, 2, NULL,
			opcl->imgxy, NULL, 0, NULL, NULL);
//	opcl->err = clEnqueueReadBuffer(opcl->commands, opcl->deg2, CL_TRUE, 0,
//			sizeof(float), &opcl->bufdeg, 0, NULL, NULL);
	opcl->err = clEnqueueReadBuffer(opcl->commands, opcl->output, CL_TRUE, 0,
			sizeof(int) * opcl->img_s, e->img.addr, 0, NULL, NULL);
	i = 0;
	(void)deg;
//	deg = opcl->bufdeg;
	/*while (i < opcl->img_s)
	{
		e->it = opcl->bufhst[i];
//		((int *)e->img.addr)[i] = opcl->bufhst[i];
		//set_pxl2(e->img, i % X_WIN, i / X_WIN, e->it);
		if (e->it >= e->fra.i_max)
			set_pxl(&e->img, i % X_WIN, i / X_WIN, e->ptf.ptcol4());
		else
			//set_pxl2(e->img, i % X_WIN, i / X_WIN, (e->it + e->fra.color[0][0]));
			//set_pxl(&e->img, i % X_WIN, i / X_WIN, interpol_color2(e->ptf.ptcol1(),
			//			e->ptf.ptcol2(),
			//			e->ptf.ptcol3(), (((float)e->it + (1 - deg))
			//				/ ((float)e->fra.i_max))));
		i++;
	}*/
}
