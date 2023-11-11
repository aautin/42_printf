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

char	*ft_ctoa(char c, int size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return ("");
	str[size] = '\0';
	while (size--)
		str[size] = c;
	return (str);
}

char	*ft_ftoa(float n)
{
	char	*str;
	float	right_part;
	char	*tp_s;
	char	*tp_s2;

	str = ft_itoa((int) n);
	tp_s = ft_ctoa('.', 1);
	tp_s2 = ft_itoa(((float) n - (int) n) * 10000000);
	ft_strlcat(str, tp_s, ft_strlen(str) + 2);
	ft_strlcat(str, tp_s2, ft_strlen(str) + 7);
	// printf("%f<-\n", 48.2009364);
	if (!str)
		return ("");
	right_part = n - ((int) n);
	return ("");
}
