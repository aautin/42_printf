/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:12 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 15:12:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_b.h"

int	ft_tag_type(char *s)
{
	int	i;

	i = 0;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	while (s[i] == '-' || s[i] == '.' || s[i] == '#'
			|| s[i] == ' ' || s[i] == '+')
		i++;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	return (s[i]);
}

int	ft_ctype(t_list *lst, va_list vaarg, char *s)
{
	if (*s == 'c')
		ft_lstadd_back(&lst, ft_lstnew(ft_c_to_str(va_arg(vaarg, int), 1)));
	else if (*s == '-' && *(s + 1) == 'c')
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_c_to_str(va_arg(vaarg, int), 1)));
		return (1);
	}
	return (0);
}

int	ft_tag(t_list *lst, va_list vaarg, char *s)
{
	if (ft_tag_type(s) == 'c')
		return (ft_ctype(lst, vaarg, s));
	// if (ft_tag_type == 'd' || ft_tag_type == 'i')
	// 	return (ft_dtype());
	// if (ft_tag_type == 's')
	// 	return (ft_stype());
	// if (ft_tag_type == 'x')
	// 	return (ft_xtype());
	// if (ft_tag_type == 'X')
	// 	return (ft_Xtype());
	// if (ft_tag_type == 'p')
	// 	return (ft_ptype());
	// if (ft_tag_type == 'u')
	// 	return (ft_utype());
	return (0);
}