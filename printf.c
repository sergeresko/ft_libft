#include <stdio.h>

int		main(void)
{
	int		i;

	i = printf("\341\210\264\n");
	printf("%d\n", i);

	i = printf("123%cZ\n", 577);
	printf("%d\n", i);

	i = printf("123%s456\n", "abc\ndef");
	printf("%d\n", i);

	i = printf("%.20\n", 42);
	printf("%d\n", i);

	i = printf("|%8.3o|\n", 2);
	printf("%d\n", i);

	i = printf("|%08.2s|\n", "abc");
	printf("%d\n", i);

	i = printf("|%8%|\n");
	printf("%d\n", i);

	i = printf("|%*.*f|\n", 10, 0, 3.14);
	printf("%d\n", i);

	i = printf("|%5.4#q8qd|\n", 42);
	printf("%d\n", i);

	return (0);
}
