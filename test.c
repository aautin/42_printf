#include "include/ft_printf.h"

typedef struct s_lst
{
	void	*content;
	struct s_lst	*next;
} t_lst;

typedef struct s_str_properties
{
	int	num_args;
	int	len_str_without_args;
	int	len_str_args;
	t_lst str_lst;
} t_str_properties;

/* above : header's part */

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
			{
				write(1, "error at position ", 18);
				i += 48;
				write(1, &i, 2);
				i -= 48;
				write(1, "\n", 1);
			}
		}
		i++;
	}
	return (num_args);
}

int	ft_myprintf(const char *text)
{
	t_str_properties	str;
	str.num_args = num_args_to_insert((const char *)text);
	return (str.num_args);
}

int	main(int argc, char *argv[])
{
	int	i;
	i = 0;
	while (i < argc)
	{
		ft_printf("\nargv[%d]: %d\n\n", i, ft_printf((const char *)argv[i]));
		ft_printf("%s\nargv[%d]: %d\n---------\n", argv[i], i, ft_myprintf((const char *)argv[i]));
		i++;
	}
	return (0);
}
