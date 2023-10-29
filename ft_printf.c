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
		/*create a funct° which add 1 to the nb_smthg and write the char*/
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			nb_printed_chars++;
		}
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			nb_printed_chars++;
		}
		else
		{
			/*something appens here with an va_arg*/
		}
	}
	return (nb_printed_chars);
}

int	main(int argc, char *argv[])
{
	char	letter;
	if (argc == 2)
	{
		letter = argv[1][0];
		if (ft_isalpha(letter))
		{
			ft_printf(" ==%printf%%== ");
			printf("%c est une lettre", letter);
		}
		else
			printf("%c n'est pas une lettre", letter);
	}
	else
		(void) letter;
	return (0);
}