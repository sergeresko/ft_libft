#include "libft.h"
#include "ft_printf.h"

#include <inttypes.h>
#include <stdio.h>


union	u_long_double
{
	long double		f;
	struct			s_i
	{
		uintmax_t		m;
		unsigned short	e;
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
//	e = u.i.e << 1 >> 1;
	if (e < 0x3fff)
		return (0.);
	e -= 0x3fff;
	if (e < 63)
	{						//
		u.i.m >>= 63 - e;	//	OR JUST u.i.m = u.i.m >> (63 - e) << (63 - e);
		u.i.m <<= 63 - e;	//
	}						//
	return (u.f);
}

/*
**	the argument need not be a whole number
**	Puts a '0' if the whole part is equal to zero.
*/

char	*entier_to_string(long double ent)
{
	char			*s;
	long double		unit;
	long double		div;

	s = PF_BUF_START;
	unit = 1.;
	while (ent / unit >= 10.)
		unit *= 10.;
	while (unit >= 1.)
	{
		div = l_entier(ent / unit);
		*(s++) = '0' + (char)div;
		ent -= div * unit;
		unit /= 10.;
	}
	if (s == BUF_START)
		*(s++) = '0';
	*s = '\0';
	return (BUF_START);
}

/*
**	the argument must be less than 1.
*/

char	*frac_to_string(long double frac, int prec)
{
	char 	*s;

	s = PF_BUF_START;
	while (prec--)
	{
		frac *= 10.;
		*(s++) = '0' + (char)frac;
		frac -= l_entier(frac);
	}
	*s = '\0';
	return (BUF_START);
}

long double	round_add(long double frac, int prec)
{
	long double		unit;

	unit = 1.;
	while (prec--)
	{
		unit *= 0.1;
		frac *= 10.;
		frac -= l_entier(frac);
	}
	if (frac >= 0.5)
		return (unit * 0.5);
	return (0.);
}

char	get_sign(const t_fmt *f, long double num)
{
	if (num < 0.)
		return ('-');
	if (f->plus)
		return ('+');
	if (f->blank)
		return (' ');
	return ('\0');
}

int		print_inf_or_nan(const t_fmt *f, char sign, const char *msg)
{
	int		val_len;

	val_len = (sign != '\0') + ft_strlen(msg);
	if (!f->left)
		ft_putnchar(' ', f->width - val_len);
	if (sign)
		ft_putchar(sign);
	ft_putstr(msg);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}

int		ft_print_float(const t_fmt *f, long double num)
{
	char	*s;
	int		prec;
	int		n_prefix;
	int		n_zeroes;
	int		n_ent;
	int		n_point;
	int		val_len;

	prec = (f->prec == PF_PREC_NONE) ? 6 : f->prec;
	num += round_add(x - l_entier(x), prec);
	s = entier_to_string(l_entier(num));
	n_ent = ft_strlen(s);

}
