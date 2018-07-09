#include "kernel.h"

__kernel void mandelbrot_gpu(__global unsigned int *out, float imax, float deg)
{
	int i;
	int idx;
	float tmp;
	float	ztmp;
	t_cmplx	c;
	t_cmplx	z;
	float zoom;

	imax = 50;
	zoom = 1024 / (2.2 - (-2.6));
	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = get_global_id(0) / zoom + -2.6;
	c.i = get_global_id(1) / zoom + -(((2.2 - -2.6) / 1024) * 720) / 2;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	while (++i < imax)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg = log(tmp / log(2.)) / log(2.);
			out[idx] = i;
			return;
		}
	}
	out[idx] = i;
}
