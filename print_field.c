int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		print_field_u(unsigned char flags, int width, int precision, unsigned n)
{
	int		len;

	digits = ft_u_len(n);
	len = ft_max(digits, precision);
	len = max(len, width);
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	write(1, s, len);
	free(s);
	return (len);
}
