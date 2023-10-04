#include <stdio.h>
#include <stdarg.h>

int	minimum(int num_args, ...)
{
	va_list	args;
	int	i;
	int	min;
	int temp;

	i = 1;
	va_start(args, num_args);
	min = va_arg(args, int); 
	while (i++ < num_args)
	{
		temp = va_arg(args, int);
		if (temp < min)
			min = temp;
	}
	va_end(args);
	return (min);
}

int	main(void)
{
	printf("%d: 3\n", minimum(1, 3));
	printf("%d: 3\n", minimum(3, 3, 6, 10));
	printf("%d: 1\n", minimum(4, 3, 2, 1, 2));
	printf("%d: 0\n", minimum(5, 3, 4, 8, 7, 0));
	printf("%d: X\n", minimum(0));
	printf("%d: 0\n", minimum(3, 0, 1, 2));
	printf("%d: -1\n", minimum(4, -1, 0, -1, 0));
	printf("%d: 1\n", minimum(5, 1, 2, 3, 2, 1));
}