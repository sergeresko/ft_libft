/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:06:36 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/03 13:50:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	e = u.i.e << 1 >> 1;	//	no need to shift, as the argument must be positive
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
	if (s == PF_BUF_START)
		*(s++) = '0';
	*s = '\0';
	return (PF_BUF_START);
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
	return (PF_BUF_START);
}

long double	round_add(long double num, int prec)
{
	long double		frac;
	long double		unit;

	frac = num - l_entier(num);
	unit = 1.;
	while (prec--)
	{
		unit *= 0.1;
		frac *= 10.;
		frac -= l_entier(frac);
	}
	if (frac >= 0.5)
		num += unit * 0.5;
	return (num);
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

int		print_inf_or_nan(const t_fmt *f, long double num)
{
//	const char	msg[][4] = {"nan", "inf"};
	union u_long_double		u;
	char		sign;
	int			val_len;
//	const char	*s;

	u.f = num;
	if (~u.i.e << 1)
		return (0);
	sign = (u.i.m << 1 >> 1) ? '\0' : get_sign(f, num);
//	s = (u.i.m << 1 >> 1) ? msg[0] : msg[1];
	val_len = (sign != '\0') + 3;
//	val_len = (sign != '\0') + ft_strlen(s);
	if (!f->left)
		ft_putnchar(' ', f->width - val_len);
	if (sign)
		ft_putchar(sign);
	ft_putstr((u.i.m << 1 >> 1) ? "nan" : "inf");
//	ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}

int		ft_print_float(const t_fmt *f, long double num)
{
	char	*s;
	char	sign;
	int		prec;
	int		val_len;

	if ((val_len = print_inf_or_nan(f, num)))
		return (val_len);
	sign = get_sign(f, num);
	prec = (f->prec == PF_PREC_NONE) ? 6 : f->prec;
	num = round_add((num < 0.) ? -num : num, prec);
	s = entier_to_string(num);
	val_len = (sign != '\0') + ft_strlen(s) + (prec > 0 || f->alt) + prec;
	if (!f->left && !f->zero)
		ft_putnchar(' ', f->width - val_len);
	if (sign)
		ft_putchar(sign);
	if (!f->left && f->zero)
		ft_putnchar('0', f->width - val_len);
	ft_putstr(s);
	if (prec > 0 || f->alt)
		ft_putchar('.');
	ft_putstr(frac_to_string(num - l_entier(num), prec));
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
