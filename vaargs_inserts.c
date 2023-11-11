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

char	ft_tag_format(char *str, int i)
{
	if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'd'
		|| str[i + 1] == 'f' || str[i + 1] == 'u' || str[i + 1] == 'x'
		|| str[i + 1] == 'X' || str[i + 1] == 'o' || str[i + 1] == 'p'
		|| str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'g'
		|| str[i + 1] == 'i')
		return (1);
	if (str[i + 1] == 'l' || str[i + 1] == 'h')
	{
		if (str[i + 2] == 'i' || str[i + 2] == 'd')
			return (2);
		if (str[i + 2] == 'l')
		{
			if (str[i + 3] == 'd' || str[i + 3] == 'i')
				return (3);
			return (0);
		}
		return (0);
	}
	return (0);
}

char	*ft_vaarg_to_str(va_list arg, char tag, char tag_sz)
{
	if (tag_sz == 1 && tag == 'c')
		return (ft_ctoa(va_arg(arg, int), 1));
	if (tag_sz == 1 && (tag == 'd' || tag == 'i'))
		return (ft_itoa(va_arg(arg, int)));
	if (tag_sz == 1 && tag == 's')
		return (ft_strdup(va_arg(arg, char *)));
	if (tag_sz == 1 && tag == 'f')
	{
		double number = (double) va_arg(arg, double);
		printf("%ld", number);
		return (ft_ftoa((float) va_arg(arg, double)));
	}
	return (NULL);
}

char	*ft_tag_to_str(va_list arg, int *i, char *str)
{
	char	tag_id;

	tag_id = ft_tag_format(str, *i);
	if (!tag_id)
		return (NULL);
	return (ft_vaarg_to_str(arg, str[*i + 1], tag_id));
}
