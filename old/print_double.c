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

double	entier(double num)
{
	union u_double	u;
	unsigned		e;

	u.f = num;
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

union	u_long_double
{
	long double		f;
	struct			s_i
	{
		uintmax_t		m;
		unsigned short	s;
	}				i;
};

long double	l_entier(long double num)
{
	union u_long_double	u;
	unsigned			e;

	u.f = num;
	e = u.i.s << 1 >> 1;
	if (e < 0x3fff)
		return (0.L);
	e -= 0x3fff;
	if (e < 63)
	{
		u.i.m >>= 63 - e;
		u.i.m <<= 63 - e;
	}
	return (u.f);
}


#define BUF_SIZE 1024

char	g_buf[BUF_SIZE + 1];

#define	BUF_START g_buf

char	*entier_to_string(double ent)
{
	char	*s;
	double	unit;
	double	div;

	s = BUF_START;
	unit = 1.;
	while (ent / unit >= 10.)
		unit *= 10.;
	while (unit >= 1.)
	{
		div = entier(ent / unit);
		*(s++) = '0' + (char)div;
		ent -= div * unit;
		unit /= 10.;
	}
	*s = '\0';
	return (BUF_START);
}

char	*frac_to_string(double frac, int prec)
{
	char 	*s;

	s = BUF_START;
	while (prec--)
	{
		frac *= 10.;
		*(s++) = '0' + (char)frac;
//		printf("%c %.20f\n", s[-1], frac);
		frac -= entier(frac);
	}
	*s = '\0';
	return (BUF_START);
}

double	round_add(double frac, int prec)
{
	double		unit;

	unit = 1.;
	while (prec--)
	{
		unit *= .1;
		frac *= 10.;
//		printf("%c %.20f\n", '0' + (char)frac, frac);
		frac -= entier(frac);
	}
//	printf("<%f|%c>", frac, frac >= .5 ? '1' : '0');
	if (frac >= .5)
		return (unit * .5);
	return (0.);
}

int		main(void)
{

	/*

//	double	x = 56789012345.67890123456789;
//	double	x = 19.99995;
//	double	x = 1.42456e30;
//	double	x = 3.149e-15;
//	double	x = 3.14e-100;
//	double	x = 1.e300 * 1.e300;	// inf
//	double	x = -1.e300 * 1.e300;	// -inf

	int		prec = 58;

	double	x = //1.000001;
				//1.9999995;
				//3.14e-56;
				//27182818280000002e24;
				//1.37e150;
				//1234567890123456789.0123456789;
				//exp10(150);
				0.14;
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

	*/


	int		prec = 6;
//	double	x = 1.99999999999999;
	double	x = 111111111111999999999999.1111111e20;
	double	frac;					//

	printf("libc: %.*f\n", prec, x);
	printf(" *10: %.*f\n", prec, x * 10.);
	frac = x - entier(x);			//	or just: x += round_add(x - entier(x), prec);
	x += round_add(frac, prec);		//
	printf("ft  : ");
	printf("%s.", entier_to_string(entier(x)));
	printf("%s\n", frac_to_string(x - entier(x), prec));


	long double	y = 123.456L;

	printf("%Lf\n%Lf\n", y, l_entier(y));

	return (0);
}
