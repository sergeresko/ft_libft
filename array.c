int		print_d(int n);

int		print_s(char *s);

typedef struct	s_fn
{
	char	*s;
	int		(*f)();
}				t_fn;

t_fn	g_fn[] =
{
	{"%d", print_d},
	{"%s", print_s},
};
