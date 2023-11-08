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

int ft_tag_format(char letter, char letter2)
{
	if (letter == '%')
		return ('%');
	else if (letter == 's' || letter == 'c' || letter == 'd' || letter == 'u'
		|| letter == 'f' || letter == 'x' || letter == 'X' || letter == 'o')
		return (1);
	else
		return (0);
}

int	ft_str_analyser(char *str, int *i, t_list **lst, va_list arg)
{
	int	tag_format;
 
	if (str[*i] == '%')
	{
		tag_format = ft_tag_format(str[*i + 1], str[*i + 2]); 
		if (tag_format == '%')
			*i += ft_str_to_lst("%", 0, &lst);
		else if (tag_format == 1 || tag_format == 2)
		{
			// ft_tag_to_str();
			// ft_str_to_str();
			*i = *i + tag_format;
		}
		else
			return (0);
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
	// 	{
	// 		if (str[++i] == '%')
	// 			ft_lstadd_back(&lst, ft_lstnew("%"));
	// 		else if (ft_tag_id(NULL, str[i], str[i + 1]))
	// 		{
	// 			ptr = va_arg(arg, int);
	// 			ft_lstadd_back(&lst, ft_lstnew(ft_va_to_str(&ptr, ft_tag_id(&i,
	// 							str[i], str[i + 1]), (char *) &str[i])));
	// 		}
	// 		else
	// 			return (write(1, "TAG-ERROR", 9));
	// 	}
	// 	else
	// 		i += ft_crop_and_lst((char *)&str[i], &lst) - 1;
	// }

int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("----> %d printed chars.",
			ft_printf(argv[1], 20, "Alexandre", 'a'));
	return (0);
}
