#include "kernel.h"
int		ft_color(uchar4 a, uchar4 b, uchar4 c, float i);
int		ft_color(uchar4 a, uchar4 b, uchar4 c, float i)
{
	uchar4 new;
	int	newc;

	newc = 0;
	i = fmax(i, 0);
	if (i <= 0.5)
	{
		new.r = a.r + (b.r - a.r) * i;
		new.g = a.g + (b.g - a.g) * i;
		new.b = a.b + (b.b - a.b) * i;
		new.a = a.a + (b.a - a.a) * i;
	}
	else
	{
		new.r = b.r + (c.r - b.r) * (i - 0.5) * 2;
		new.r = b.g + (c.g - b.g) * (i - 0.5) * 2;
		new.r = b.b + (c.b - b.b) * (i - 0.5) * 2;
		new.r = b.a + (c.a - b.a) * (i - 0.5) * 2;
	}
	newc = convert_int(new.r << 16) | convert_int(new.g << 8) | convert_int(new.b);
	return (newc);
}

__kernel void mandelbrot_gpu(__global int *out, __global t_fractal *e)
{
	int i;
	int idx;
	float tmp;
	float ztmp;
	float deg;
	t_cmplx	c;
	t_cmplx	z;
	uchar4 a;
	uchar4 b;
	uchar4 d;

	a = (uchar4)(255, 0, 0, 0);
	b = (uchar4)(0, 0, 255, 0);
	d = (uchar4)(200, 200, 200, 0);
	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = get_global_id(0) / e->zoom + e->x1;
	c.i = get_global_id(1) / e->zoom + e->y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	while (++i < e->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg += log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ft_color(b, d, a, (((float)i + (1 - deg)) / e->i_max));
			return;
		}
	}
	out[idx] = 0x00000000;
}
