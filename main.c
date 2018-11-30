#include "ft_printf.h"

#include <unistd.h>
#include <wchar.h>

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int			res;
	wchar_t		wc = 945;//L'我';
	wchar_t		ws[] = L"абвгд";
//	wchar_t		wc = L'ы';
	char		*s;

//	setlocale(LC_ALL, "");
	printf("%d\n", MB_CUR_MAX);
	res = printf("%dabc%4lc", 5, wc);
	printf("\n%d\n", res);
	res = printf("|%.4ls|", ws);
	printf("\n%d\n", res);
	
	setlocale(LC_ALL, "");
	printf("%d\n", MB_CUR_MAX);
	res = printf("abc%4lc", wc);
	printf("\n%d\n", res);
	res = printf("|%-6.5ls|", ws);
	printf("\n%d\n", res);
	
	setlocale(LC_ALL, "C");
	printf("%d\n", MB_CUR_MAX);
	res = printf("acb%4lc", wc);
	printf("\n%d\n", res);
	res = printf("|%.4ls|", ws);
	printf("\n%d\n", res);

/*	s = unicode_to_utf8(wc);
	printf("%s\n", s);
	printf("%4lc\n", L'我');
	printf("\n----\n");
	for (int i = 126; i < 300; ++i)
	{
		res = printf("%3d: %.2lc", i, i);
		printf("----(%d)\n", res);
	}
*/
	return (0);
}
