#include "kernel.h"

__kernel void mandelbrot_gpu(__global unsigned int *out, double deg)
{
	int i;
	int idx;
	double tmp;
	double	ztmp;
	t_cmplx	c;
	t_cmplx	z;
	double zoom;

	zoom = 1024 / (2.2 - (-2.6));
	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = get_global_id(0) / zoom + (-2.6);
	c.i = get_global_id(1) / zoom + -((((2.2 - (-2.6)) / 1024) * 720) / 2);
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	while (++i < 100)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = (z.r * z.r + z.i * z.i) / 2.0;
		if (tmp >= 4)
		{
			deg = log(tmp / log(2.)) / log(2.);
			out[idx] = 0xfffffff;
			break;
		}
	}
	out[idx] = i;
}
