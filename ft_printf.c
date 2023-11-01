/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_is_tag(char l1, char l2)
{
	if (l1 == 'd' || l1 == 'f' || l1 == 'c' || l1 == 's' || l1 == 'p'
		|| l1 == 'x' || l1 == 'X' || l1 == 'o' || l1 == 'u' || l1 == 'i')
		return (1);
	else if ((l1 == 'l' && (l2 == 'd' || l2 == 'i')))
		return (2);
	else if ((l1 == 'h' && (l2 == 'd' || l2 == 'i')))
		return (2);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb_printed_chars;
	va_list	args;

	i = -1;
	nb_printed_chars = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (ft_is_tag(str[i + 1], str[i + 2]))
			{
				write(1, "VAR", 3);
				if (ft_is_tag(str[i + 1], str[i + 2]) == 2)
					i++;
				i++;
			}
			else if (str[i + 1] == '%')
			{
				write(1, "%", 1);
				nb_printed_chars++;				
				i++;
			}
			else
				return (0);
		}
		else
		{
			write(1, &str[i], 1);
			nb_printed_chars++;
		}
	}
	return (nb_printed_chars);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_printf(argv[1]);
	return (0);
}