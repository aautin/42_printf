#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	num_args_to_insert(const char *text)
{
	int num_args;
	int	i;

	num_args = 0;
	i = 0;
	while (text[i])
	{
		if (text[i] == '%')
		{
			if (text[i + 1] == '%')
				i++;
			else if ('a' <= text[i + 1] && text[i + 1] <= 'z')
				num_args++;
			else
				write(5, "error\n", 5);
		}
		i++;
	}
	return (num_args);
}

int	ft_printf(const char *text)
{
	int	num_args;
	num_args = num_args_to_insert((const char *)text);
	return (num_args);
}

int	main(int argc, char *argv[])
{
	int	i;
	i = 1;
	char	*text1 = "";
	char	*text2 = ft_strdup(text1);
	char	*text3 = ft_strdup(text2);
	while (i < argc)
	{
		printf("argv[%d]: %d (%s)\n", i, ft_printf((const char *)argv[i]), argv[i]);
		i++;
	}
	return (0);
}