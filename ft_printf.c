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

int	ft_tag_id(int *i, char l1, char l2)
{
	if (l1 == 'd' || l1 == 'f' || l1 == 'c' || l1 == 's' || l1 == 'p'
		|| l1 == 'x' || l1 == 'X' || l1 == 'o' || l1 == 'u' || l1 == 'i')
	{
		return (1);
	}
	else if ((l1 == 'l' && (l2 == 'd' || l2 == 'i')))
	{
		if (i)
			*i = *i + 1;
		return (2);
	}
	else if ((l1 == 'h' && (l2 == 'd' || l2 == 'i')))
	{
		if (i)
			*i = *i + 1;
		return (2);
	}
	else
	{
		if (i)
			*i = *i - 1;
		return (0);
	}
}

int	ft_crop_and_lst(char *str, t_list **lst)
{
	int	j;
	char	*temp_str;

	j = 0;
	while (str[j] && str[j] != '%')
		j++;
	temp_str = (char *) malloc((j + 1) * sizeof(char));
	if (!temp_str)
		return (0);
	ft_strlcpy(temp_str, str, j + 1);
	ft_lstadd_back(lst, ft_lstnew(temp_str));
	free(temp_str);
	return (j);
}

int ft_print_result(t_list **lst)
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

void	*ft_va_str(int arg, int tag_id)
{
	return ("VAR");
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_list	*lst;
	va_list	arg;

	i = -1;
	lst = ft_lstnew("");
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			// here, have to do something
			if (str[++i] == '%')
				ft_lstadd_back(&lst, ft_lstnew("%"));
			else if (ft_tag_id(NULL, str[i], str[i + 1]))
			{
				// here have to handle the adress of va_arg returned value
				// but lack of line space (maybe just 2 more).
				ft_lstadd_back(&lst, ft_lstnew(ft_va_str(va_arg(arg, int),
					(ft_tag_id(&i, str[i], str[i + 1])))));
			}
			else
				return(write(1, "TAG-ERROR", 9));
		}
		else
			i += ft_crop_and_lst((char *)&str[i], &lst) - 1;
	}
	va_end(arg);
	return (ft_print_result(&lst));
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("\n%d\n", ft_printf(argv[1]));
	return (0);
}

/*
I : je
you (singular) : tu
he/she/it : il/elle
we : nous
you (plural) : vous
they : ils(b)/elles(g)/ils(mix)

one : un
two : deux
three : trois
four : quatre
five : cinq
six : six
seven : sept
eight : huit
nine : neuf
ten : dix */