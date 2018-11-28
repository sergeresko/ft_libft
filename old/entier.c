#include <inttypes.h>
#include <stdio.h>

union	u_double
{
	double		f;
	uintmax_t	i;
};

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
	{
		u.i >>= 52 - e;
		u.i <<= 52 - e;
	}
	return (u.f);
}

#define BUF_SIZE 1024

char	s1[BUF_SIZE + 1];
char	s2[BUF_SIZE + 1];

char	digit(double mod)
{
	return ((char)(mod + .4) + '0');
}

char	*entier_s(double ent)
{
	char	*s;
	double	fr;

	s = s1 + BUF_SIZE;
	*s = '\0';
	while (ent > .5)
	{
		ent /= 10.;
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

	s = s2;
	while (prec--)
	{
		x *= 10;
		ent = entier(x);
		*(s++) = digit(ent);
//		printf("x = %f, ent = %f", x, ent);
		x -= ent;
	}
	*s = '\0';
	return (s2);
}

double	round_add(double frac, int precision)
{
	double		u;
	int			p;

	p = precision;
	while (p--)
	{
		frac *= 10.;
		frac -= entier(frac);
		printf("%.20f\n", frac);
	}
	if (frac >= .5)
	{
		p = precision;
		u = 1.;
		while (p--)
			u /= 10.;
		return (u / 10.);
	}
	return (0.);
}

int		main(void)
{
//	double	x = 56789012345.67890123456789;
	double	x = 19.99995;
//	double	x = 1.42456e30;
//	double	x = 3.149e-15;
//	double	x = 3.14e-100;
//	double	x = 1.e300 * 1.e300;	// inf
//	double	x = -1.e300 * 1.e300;	// -inf

	int		prec = 110;
	double	ent = entier(x);
	double	frac = x - ent;

	printf(" x  = %.*f\n", prec, x);
	printf("[x] = %.*f\n", prec, ent);
	printf("{x} = %.*f\n", prec, frac);
	printf("orig: %.*f\n", prec, x);
	printf("my  : %s.%s\n", entier_s(ent), frac_s(frac, prec));

	printf("\n%4f
	double	ra = round_add(x, 4);
	printf("round_add:\n%.*f\n", prec, ra);
	x += ra;
	printf("added:\n%.*f\n", prec, x);
	ent = entier(x);
	frac = x - ent;
	printf("my:\n %s.%s\n", entier_s(ent), frac_s(frac, 4));
//	printf("%c\n", '0' + (char)1.8);
	return (0);
}
