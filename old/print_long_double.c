#include <inttypes.h>
#include <stdio.h>

union	u_long_double
{
	long double		f;
	struct			s_i
	{
		uintmax_t		m;
		unsigned short	s;
	}				i;
};

/*
**	returns a positive integral part of the argument
*/

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

char	*entier_to_string(long double ent)
{
	char			*s;
	long double		unit;
	long double		div;

	s = BUF_START;
	unit = 1.L;
	while (ent / unit >= 10.L)
		unit *= 10.L;
	while (unit >= 1.L)
	{
		div = l_entier(ent / unit);
		*(s++) = '0' + (char)div;
		ent -= div * unit;
		unit /= 10.L;
	}
	*s = '\0';
	return (BUF_START);
}

char	*frac_to_string(long double frac, int prec)
{
	char 	*s;

	s = BUF_START;
	while (prec--)
	{
		frac *= 10.L;
		*(s++) = '0' + (char)frac;
//		printf("%c %.20f\n", s[-1], frac);
		frac -= l_entier(frac);
	}
	*s = '\0';
	return (BUF_START);
}

long double	round_add(long double frac, int prec)
{
	long double		unit;

	unit = 1.L;
	while (prec--)
	{
		unit *= .1L;
		frac *= 10.L;
//		printf("%c %.20f\n", '0' + (char)frac, frac);
		frac -= l_entier(frac);
	}
//	printf("<%f|%c>", frac, frac >= .5 ? '1' : '0');
	if (frac >= .5L)
		return (unit * .5L);
	return (0.L);
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


	int		prec = 2;
//	double	x = 1.99999999999999;
	long double	x = 0.5947;
	long double	frac;					//

	printf("libc: %.*Lf\n", prec, x);
//	printf(" *10: %.*Lf\n", prec, x * 10.);
	frac = x - l_entier(x);			//	or just: x += round_add(x - l_entier(x), prec);
	x += round_add(frac, prec);		//
	printf("ft  : ");
	printf("%s.", entier_to_string(/*l_entier(*/x/*)*/));
	printf("%s\n", frac_to_string(x - l_entier(x), prec));


	long double	y = 123.456L;

	printf("%Lf\n%Lf\n", y, l_entier(y));

	return (0);
}
