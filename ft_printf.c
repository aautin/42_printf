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

int	ft_print_result(t_list **lst)
{
	int	nb_printed_chars;
	int	i;

	nb_printed_chars = 0;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		i = 0;
		while (((char *)(*lst)->content)[i])
		{
			write(1, &((char *)(*lst)->content)[i], 1);
			i++;
		}
		nb_printed_chars += i;
	}
	return (nb_printed_chars);
}

int	ft_str_to_lst(char *str, int i, t_list ***lst)
{
	char	*temp;
	int		j;

	if (str[0] == '%')
	{
		ft_lstadd_back(*lst, ft_lstnew("%"));
		return (1);
	}
	j = 0;
	while (str[i + j] && str[i + j] != '%')
		j++;
	temp = (char *)malloc((j + 1) * sizeof(char));
	if (!temp)
		return (0);
	j = 0;
	while (str[i] && str[i] != '%')
	{
		temp[j] = str[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	ft_lstadd_back(*lst, ft_lstnew(temp));
	free(temp);
	return (j - 1);
}

int ft_tag_format(char letter, char letter2, char letter3)
{
	if (letter == '%')
		return ('%');
	else if (letter == 's' || letter == 'c' || letter == 'd' || letter == 'u'
		|| letter == 'f' || letter == 'x' || letter == 'X' || letter == 'o')		// missing some cases here
		return (1);
	else if (letter == 'l' || letter == 'h')
	{
		if (letter2 == 'l')
		{
			if (letter3 == 'd' || letter3 == 'i')
				return (3);
			else
				return (0);
		}
		else if (letter2 == 'd' || letter2 == 'i')
			return(2);
		else
			return (0);
	}
	else
		return (0);
}

char	*ft_char_to_str(int c, int size)
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

void	ft_tag_to_str(int tag_format, va_list arg, t_list ***lst, char *str)
{
	if (tag_format == 1)
	{
		if (str[1] == 'c')
			ft_str_to_lst(ft_char_to_str(va_arg(arg, int), 1), 0, lst);
	}
}

int	ft_str_analyser(char *str, int *i, t_list **lst, va_list arg)
{
	int	tag_format;
 
	if (str[*i] == '%')
	{
		tag_format = ft_tag_format(str[*i + 1], str[*i + 2], str[*i + 3]); 
		if (tag_format == '%')
			*i += ft_str_to_lst("%", 0, &lst);
		else if (!tag_format)
			return (0);
		else
		{
			ft_tag_to_str(tag_format, arg, &lst, &str[*i]);
			*i = *i + tag_format;
		}
		return (1);
	}
	else
		*i += ft_str_to_lst(str, *i, &lst);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_list	*lst;
	va_list	arg;
	int		i;

	va_start(arg, str);
	lst = ft_lstnew("");
	i = 0;
	while (str[i])
	{
		if (!ft_str_analyser((char *) str, &i, &lst, arg))
		{
			va_end(arg);
			return (0);
		}
		i++;
	}
	va_end(arg);
	return (ft_print_result(&lst));
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("--> %d printed chars.",
			ft_printf(argv[1], 'a', 'c', 48));
	return (0);
}
