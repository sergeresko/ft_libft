#include <inttypes.h>
#include <stdio.h>

union	u_double
{
	double		f;
	uintmax_t	i;
};


/*
**	returns a positive integral part of the argument
*/

double	entier(double x)
{
	unsigned int	e;
	union u_double	u;

	u.f = x;
	e = u.i << 1 >> 53;		// biased exponent
	if (e < 0x3ff)
		return (0.);
	e -= 0x3ff;				// unbiased exponent
	if (e < 52)
	{						// OR JUST u.i = u.i >> (52 - e) << (52 - e);
		u.i >>= 52 - e;
		u.i <<= 52 - e;
	}
	return (u.f);
}

#define BUF_SIZE 1024

char	g_s1[BUF_SIZE + 1];
char	g_s2[BUF_SIZE + 1];

char	digit(double mod)
{
	return ((char)(mod + .4) + '0');
}

char	*entier_s(double ent)
{
	char	*s;
	double	fr;

	s = g_s1 + BUF_SIZE;
	*s = '\0';
	while (ent > .9)		// why ?
	{
		ent /= 10.;
//		ent *= .1;
		fr = ent - entier(ent);
		*(--s) = digit(10. * fr);
//		printf("ent = %f, fr = %f\n", ent, fr);
		ent -= fr;
	}
	return (s);
}

char	*frac_s(double x, int prec)
{
	char 	*s;
	double	ent;

	s = g_s2;
	while (prec--)
	{
		x *= 10;
		ent = entier(x);
		*(s++) = '0' + (char)ent;
//		printf("x = %f, ent = %f\n", x, ent);			//
		x -= ent;
	}
	*s = '\0';
	return (g_s2);
}

double	round_add(double frac, int precision)
{
	double		u;		// unit
	int			p;

	printf("%.20f\n", frac);
	p = precision;
	while (p--)
	{
		frac *= 10.;
		frac -= entier(frac);
		printf("%.20f\n", frac);
	}
	if (frac < .5)
		return (0.);
	p = precision;
	u = 1.;
	while (p--)
		u /= 10.;
	return (u);
}

double	exp10(unsigned n)
{
	double	x;

	x = 1.;
	while (n--)
		x *= 10.;
	return (x);
}

int		main(void)
{
//	double	x = 56789012345.67890123456789;
//	double	x = 19.99995;
//	double	x = 1.42456e30;
//	double	x = 3.149e-15;
//	double	x = 3.14e-100;
//	double	x = 1.e300 * 1.e300;	// inf
//	double	x = -1.e300 * 1.e300;	// -inf

	int		prec = 6;

	double	x = //1.000001;
				//1.9999995;
				//3.14e-56;
				//27182818280000002e24;
				//1.37e150;
				//1234567890123456789.0123456789;
				exp10(150);
	double	ent = entier(x);
	double	frac = x - ent;

	printf("printf:\n");
	printf("    x     = %.*f\n", prec + 10, x);
	printf("   [x]    = %.*f\n", prec + 10, ent);
	printf("   {x}    = %.*f\n", prec + 10, frac);

	double	ra = round_add(x, prec);

	printf("round_add = %.*f\n", prec + 10, ra);

	double	x_new = x + ra;
	double	ent_new = entier(x_new);
	double	frac_new = x_new - ent_new;

	printf("printf:\n");
	printf("  x_new   = %.*f\n", prec + 10, x_new);
	printf(" [x_new]  = %.*f\n", prec + 10, ent_new);
	printf(" {x_new}  = %.*f\n", prec + 10, frac_new);

	printf("printf:\n");
	printf("    x     = %.*f\n", prec, x);
	printf("my:\n");
	printf("    x     = %s.%s\n", entier_s(ent_new), frac_s(frac_new, prec));

	unsigned	n = 30;
	printf("10^%u = %f\n", n, exp10(n));

	return (0);
}
