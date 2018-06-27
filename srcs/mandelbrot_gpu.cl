#include "kernel.h"

__kernel void mandelbrot_gpu(__global t_fractal *e, __write_only image2d_t out, float deg)
{
	int i;
	int2 idx;
	float tmp;
	float	ztmp;
	int4	col;
	int4	col2;
	t_cmplx	c;
	t_cmplx	z;

	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = get_global_id(0) / e->zoom + e->x1;
	c.i = get_global_id(1) / e->zoom + e->y1;
	idx = (int2)(get_global_id(0), get_global_id(1));
	col = (int4)(255, 255, 255, 0);
	col2 = (int4)(0, 0, 0, 0);
	while (++i < get_global_size(0))
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0;
		if (tmp >= 4)
		{
			deg = log(tmp / log(2.)) / log(2.);
			write_imagei(out, idx, (col * (int4)deg));
		}
		write_imagei(out, idx, col);
	}
}
