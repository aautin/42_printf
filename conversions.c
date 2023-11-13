/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int n, int *printed)
{
	if (9 < n)
	{
		ft_putnbr_len(n / 10, printed);
		ft_putchar_len((n % 10) + 48, printed);
	}
	else if (n < 0)
	{
		ft_putchar_len('-', printed);
		if (-10 >= n)
			ft_putnbr_len((-(n / 10)), printed);
		ft_putchar_len(-(n % 10) + 48, printed);
	}
	if (0 <= n && n <= 9)
		ft_putchar_len((n % 10) + 48, printed);
}

void	ft_putunsign_len(unsigned int n, int *printed)
{
	if (9 < n)
	{
		ft_putunsign_len(n / 10, printed);
		ft_putchar_len((n % 10) + 48, printed);
	}
	if (n <= 9)
		ft_putchar_len((n % 10) + 48, printed);
}

void	ft_putstr_len(char *str, int *printed)
{
	int	i;

	if (!str)
		ft_putstr_len("(null)", printed);
	else
	{
		i = 0;
		while (str[i])
		{
			ft_putchar_len(str[i], printed);
			i++;
		}
	}
}

void	ft_puthexa_len(unsigned long long nb, int *printed, int maj)
{
	char	*hexabase;

	if (maj)
		hexabase = "0123456789ABCDEF";
	else
		hexabase = "0123456789abcdef";
	if (nb < 16)
		ft_putchar_len(hexabase[nb], printed);
	else
	{
		ft_puthexa_len(nb / 16, printed, maj);
		ft_putchar_len(hexabase[nb % 16], printed);
	}
}

void	ft_putptr_len(unsigned long long adress, int *printed)
{
	if (!adress)
		ft_putstr_len("(nil)", printed);
	else
	{
		ft_putstr_len("0x", printed);
		ft_puthexa_len(adress, printed, 0);
	}
}
