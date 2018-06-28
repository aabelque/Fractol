/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:30:12 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/28 17:42:22 by aabelque         ###   ########.fr       */
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
		ft_putendl("Error: Fail to create kernel");
		exit(EXIT_FAILURE);
	}
}

void		create_prog(t_opencl *opcl)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	tmp = NULL;
	fd = open("srcs/mandelbrot_gpu.cl", O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0 || fd < 0)
			exit(0);
		if (tmp == NULL)
		{
			tmp = ft_strnew(ft_strlen(buf));
			tmp = buf;
		}
		else
		{
			tmp = ft_strjoin(opcl->kernel_src, buf);
			free((char *)opcl->kernel_src);
		}
		opcl->kernel_src = tmp;
	}
	close(fd);
	if (!(opcl->program = clCreateProgramWithSource(opcl->context, 1,
					(const char **)&opcl->kernel_src, NULL, &opcl->err)))
	{
		ft_putendl("Error: Fail to create program with source");
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
		fprintf(stderr,"Build log: \n%s\n", errbuf);
		ft_putendl("Error: Fail to build program");
		exit(EXIT_FAILURE);
	}
}

void			opencl_init(t_opencl *opcl)
{
	if (clGetPlatformIDs(1, &opcl->platform_id, NULL) != CL_SUCCESS)
	{
		ft_putendl("Error: Fail to get a platformID");
		exit(EXIT_FAILURE);
	}
	if (clGetDeviceIDs(opcl->platform_id, opcl->dev_type, 1,
			&opcl->device_id, &opcl->num_dev) != CL_SUCCESS)
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
	opcl->img_s = X_WIN * Y_WIN;
	opcl->bufhst = (int *)ft_memalloc(opcl->img_s * sizeof(int)); 
//	opcl->input = clCreateBuffer(opcl->context, CL_MEM_READ_ONLY,
//			sizeof(int), NULL, NULL);
	opcl->output = clCreateBuffer(opcl->context, CL_MEM_WRITE_ONLY,
			sizeof(int) * opcl->img_s, NULL, NULL);
	create_prog(opcl);
	create_kernel(opcl->program, &opcl->kernel[0], "mandelbrot_gpu");
//	create_kernel(opcl->program, opcl->kernel[1], "julia_gpu");
//	create_kernel(opcl->program, opcl->kernel[2], "multibrot_gpu");
//	create_kernel(opcl->program, opcl->kernel[3], "burningship_gpu");

}

void			opencl_draw(t_opencl *opcl, t_env *e, double deg)
{
	size_t		i;
	opcl->err = 0;
	//opcl->err = clSetKernelArg(*opcl->kernel, 0, sizeof(t_fractal), &opcl->input);
	opcl->err |= clSetKernelArg(*opcl->kernel, 0, sizeof(cl_mem), &opcl->output);
	opcl->err |= clSetKernelArg(*opcl->kernel, 1, sizeof(double), &deg);
//	opcl->err = clEnqueueWriteBuffer(opcl->commands, opcl->input, CL_TRUE, 0,
//			sizeof(int), (const void *)&opcl->fra, 0, NULL, NULL);
	opcl->err = clEnqueueNDRangeKernel(opcl->commands, *opcl->kernel, 2, NULL,
			opcl->imgxy, NULL, 0, NULL, NULL);
	opcl->err = clEnqueueReadBuffer(opcl->commands, opcl->output, CL_TRUE, 0,
			sizeof(int) * opcl->img_s, opcl->bufhst, 0, NULL, NULL);
	i = 0;
	while (i < opcl->img_s)
	{
		e->it = opcl->bufhst[i];
//		((int *)e->img.addr)[i] = opcl->bufhst[i];
		//set_pxl2(e->img, i % X_WIN, i / X_WIN, e->it);
		if (e->it > 50)
			set_pxl(&e->img, i % X_WIN, i / X_WIN, e->ptf.ptcol4());
		else
			set_pxl(&e->img, i % X_WIN, i / X_WIN, interpol_color2(e->ptf.ptcol1(),
						e->ptf.ptcol2(),
						e->ptf.ptcol3(), (((double)e->it + (1 - deg))
							/ ((double)e->fra.i_max))));
		i++;
	}
}
