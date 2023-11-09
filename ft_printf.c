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


int	ft_print_result(t_list *lst)
{
	int	nb_printed_chars;
	int	i;

	nb_printed_chars = 0;
	while (lst->next)
	{
		lst = lst->next;
		i = 0;
		while (((char *)lst->content)[i])
		{
			write(1, &((char *)lst->content)[i], 1);
			i++;
		}
		nb_printed_chars += i;
	}
	return (nb_printed_chars);
}


int	ft_str_analyser(char *str, int *i, t_list *lst, va_list arg)
{
	char	*ptr;

	if (str[*i] == '%')
	{
		if (str[*i + 1] == '%')
			ft_lstadd_back(&lst, ft_lstnew("%"));
		else 
		{
			ptr  = ft_tag_to_str(arg, i, str);
			if (!ptr)
				return (0);
			ft_lstadd_back(&lst, ft_lstnew(ptr));
			free(ptr);
		}
		(*i)++;
	}
	else
	{
		ptr = ft_ctoa(str[*i], 1);
		if (!ptr)
			return (0);
		ft_lstadd_back(&lst, ft_lstnew(ptr));
		free(ptr);
	}
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
		if (!ft_str_analyser((char *) str, &i, lst, arg))
		{
			ft_lstclear(&lst, free);
			va_end(arg);
			return (0);
		}
		i++;
	}
	va_end(arg);
	i = ft_print_result(lst);
	ft_lstclear(&lst, free);
	return (i);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("--> %d printed chars.",
			ft_printf(argv[1], 48, 48.2, "oui"));
	return (0);
}
