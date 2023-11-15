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

char	*ft_c_to_str(char c, int nb)
{
	char	*str;
	

	str = (char *)malloc((nb + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, c, nb);
	str[nb] = '\0';
	return (str);
}

int		ft_printlst(t_list *lst)
{
	int	i;
	int printed_chars;

	printed_chars = 0;
	while (lst)
	{
		i = 0;
		while (((char *) lst->content)[i])
		{
			ft_putchar_fd(((char *) lst->content)[i], 1);
			i++;
		}
		printed_chars += i;
		lst = lst->next;
	}
	return (printed_chars);
}

int		ft_printf(const char *s, ...)
{
	va_list	vaarg;
	t_list	*lst;

	va_start(vaarg, s);
	lst = ft_lstnew("");
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '\0')
			s += ft_tag(lst, vaarg, (char *) (s + 1)) + 1;
		else
			ft_lstadd_back(&lst, ft_lstnew(ft_c_to_str(*s, 1)));
		s++;
	}
	va_end(vaarg);
	return (ft_printlst(lst));
}
