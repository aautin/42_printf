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

int	ft_tag_index(int *i, char l1, char l2)
{
	if (l1 == 'd' || l1 == 'f' || l1 == 'c' || l1 == 's' || l1 == 'p'
		|| l1 == 'x' || l1 == 'X' || l1 == 'o' || l1 == 'u' || l1 == 'i')
	{
		(*i)++;
		return (1);
	}
	else if ((l1 == 'l' && (l2 == 'd' || l2 == 'i')))
	{
		*i = *i + 2;
		return (2);
	}
	else if ((l1 == 'h' && (l2 == 'd' || l2 == 'i')))
	{
		*i = *i + 2;
		return (2);
	}
	else
		return (0);
}

void	ft_add_char_and_actualize(int *i, int *nb_printed_chars, char letter)
{
	write(1, &letter, 1);
	(*nb_printed_chars)++;
	(*i)++;
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
			if (ft_tag_index(&i, str[i + 1], str[i + 2]))
				write(1, "[]", 3);
			else if (str[i + 1] == '%')
				ft_add_char_and_actualize(&i, &nb_printed_chars, '%');
			else
				return (0);
		}
		else
			ft_add_char_and_actualize(&i, &nb_printed_chars, (char) &str[i]);
	}
	return (nb_printed_chars);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_printf(argv[1]);
	return (0);
}