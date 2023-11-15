/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:18 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 15:28:45 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_b.h"

char	*ft_c_to_str(char c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int		ft_printlst(void)
{
	return (0);
}

int		ft_printf(const char *s, ...)
{
	int		printed_chars;
	va_list	vaarg;
	t_list	*lst;

	printed_chars = 0;
	va_start(vaarg, s);
	lst = ft_lstnew("");
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '\0')
		{
			break ;
		}
		else
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_c_to_str(*s)));
		}
		s++;
	}
	
	va_end(vaarg);
	return (0);
}
