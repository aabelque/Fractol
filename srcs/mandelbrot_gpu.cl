uchar4			color_y(void);
typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef	struct		s_cmplx
{
	float			r;
	float			i;
}					t_cmplx;

typedef	struct		s_fractal
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zoom;
	float			julcr;
	float			julci;
	float			n;
	float			size_tree;
	float			size_tree2;
	float			i_max2;
	float			smth;
	float			deg;
	int				r;
	int				g;
	int				b;
	int				i_max;
}					t_fractal;

uchar4			color_y(void)
{
	uchar4	col;
	
	col = uchar4(0, 255, 0, 0);
	return (col);
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
			//out[idx] = (int)color_y();
			out[idx] = i;
			return;
		}
	}
	out[idx] = i;
}
