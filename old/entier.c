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

int		main(void)
{
	double	x = 1234567890123456.7890;
	int		prec = 19;
	double	ent = entier(x);
	double	frac = x - ent;

	printf(" x  = %.*f\n", prec, x);
	printf("[x] = %.*f\n", prec, ent);
	printf("{x} = %.*f\n", prec, frac);
	printf("orig: %.*f\n", prec, x);
	printf("my  : %s.%s\n", entier_s(ent), frac_s(frac, prec));
//	printf("%c\n", '0' + (char)1.8);
	return (0);
}
