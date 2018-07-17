#include "kernel.h"

int		ch_col(__global t_fractal *c, float iter);

int		ch_col(__global t_fractal *c, float iter)
{
	int		r;
	int		g;
	int		b;

	if (iter >= c->i_max)
		return (0);
	else
	{
		r = sin((float)(fmod((float)(c->r_freq * iter + c->r_ph), (float)(2 * M_PI))))
			* c->clr2 + c->clr;
		g = sin((float)(fmod((float)(c->g_freq * iter + c->g_ph), (float)(2 * M_PI))))
			* c->clr2 + c->clr;
		b = sin((float)(fmod((float)(c->b_freq * iter + c->b_ph), (float)(2 * M_PI))))
			* c->clr2 + c->clr;
		return (r << 16 | g << 8 | b);
	}
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
			deg = log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ch_col(e, deg);
			return;
		}
	}
	out[idx] = 0x00000000;
}

__kernel void julia_gpu(__global int *out, __global t_fractal *e)
{
	int i;
	int idx;
	float tmp;
	float ztmp;
	float deg;
	t_cmplx	c;
	t_cmplx	z;

	i = -1;
	z.r = get_global_id(0) / e->zoom + e->x1;
	z.i = get_global_id(1) / e->zoom + e->y1;
	c.r = e->julcr;
	c.i = e->julci;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	while (++i < e->i_max)
	{
		ztmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg = log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ch_col(e, deg);
			return;
		}
	}
	out[idx] = 0x00000000;
}

__kernel void multibrot_gpu(__global int *out, __global t_fractal *e)
{
	int i;
	int idx;
	float tmp;
	float ztmp;
	float deg;
	t_cmplx	c;
	t_cmplx	z;

	i = -1;
	z.r = 0;
	z.i = 0;
	c.r = get_global_id(0) / e->zoom + e->x1;
	c.i = get_global_id(1) / e->zoom + e->y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	while (++i < e->i_max)
	{
		ztmp = z.r;
		z.r = pow((float)((z.r * z.r) + (z.i * z.i)), (float)(e->n / 2))
			* cos((float)(e->n * atan2((float)z.i, (float)z.r))) + c.r;
		z.i = pow((float)((ztmp * ztmp) + (z.i * z.i)), (float)(e->n / 2))
			* sin((float)(e->n * atan2((float)z.i, (float)ztmp))) + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg = log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ch_col(e, deg);
			return;
		}
	}
	out[idx] = 0x00000000;
}

__kernel void burningship_gpu(__global int *out, __global t_fractal *e)
{
	int i;
	int idx;
	float tmp;
	float ztmp;
	float deg;
	t_cmplx	c;
	t_cmplx	z;

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
		z.i = fabs((float)(2 * z.i * ztmp)) + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg = log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ch_col(e, deg);
			return;
		}
	}
	out[idx] = 0x00000000;
}

__kernel void tricorn_gpu(__global int *out, __global t_fractal *e)
{
	int i;
	int idx;
	float tmp;
	float ztmp;
	float deg;
	t_cmplx	c;
	t_cmplx	z;

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
		z.i = -2 * z.i * ztmp + c.i;
		tmp = log(z.r * z.r + z.i * z.i) / 2.0f;
		if (tmp >= 4)
		{
			deg = log(tmp / log(e->smth)) / log(e->smth);
			out[idx] = ch_col(e, deg);
			return;
		}
	}
	out[idx] = 0x00000000;
}
