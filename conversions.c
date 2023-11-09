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

char	*ft_ftoa(float n)
{
	char	*str;
	int     size;
    int		left_part;
    float   right_part;

    left_part = n;
    size = 1 + 6 + 1; // 1st natural nb, 6 decimals nb, the '.'
    while (left_part / 10)
    {
        left_part = left_part / 10;
        size++;
    }
    right_part = n  - ((int) n);
    printf("%f", right_part);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return ("");
    str[size] = '\0';
    str[size - 6] = '.'
    // here have to cpy the float nb into the array
	return (str);
}

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
