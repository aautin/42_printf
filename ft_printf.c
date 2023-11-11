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

#include "ft_printf.h"

void	ft_putchar_len(int a, int *printed)
{
	ft_putchar_fd(a, 1);
	*printed += 1;
}

static void	ft_vaarg(const char *str, va_list args, int *printed)
{	
	if (*str == 'c')
		ft_putchar_len(va_arg(args, int), printed);
	else if (*str == 'd' || *(str) == 'i')
		ft_putnbr_len(va_arg(args, int), printed);
	else if (*str == 's')
		ft_putstr_len(va_arg(args, char *), printed);
	else if (*str == 'x')
		ft_puthexa_len(va_arg(args, unsigned int), printed, 0);
	else if (*str == 'X')
		ft_puthexa_len(va_arg(args, unsigned int), printed, 1);
	else if (*str == 'p')
		ft_putptr_len(va_arg(args, unsigned long), printed);
	else if (*str == 'u')
		ft_putunsign_len(va_arg(args, unsigned int), printed);
	else if (*str == '%')
		ft_putchar_len(*str, printed);
}

int	ft_printf(const char *str, ...)
{
	int		printed_chars;
	va_list	args;

	printed_chars = 0;
	va_start(args, str);
	while (*str)
	{	
		if (*str == '%' && *(str + 1) != '\0')
			ft_vaarg(++str, args, &printed_chars);
		else
			ft_putchar_len(*str, &printed_chars);
		str++;
	}
	va_end(args);
	return (printed_chars);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_printf(argv[1], argv, 48, 48, "oui");
		printf("|\n");
		printf(argv[1], argv, 48, 48, "oui");
	}
	return (0);
}
