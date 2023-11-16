/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:13:34 by aautin            #+#    #+#             */
/*   Updated: 2023/11/16 17:07:13 by aautin           ###   ########.fr       */
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

int	ft_c_leftpad(char *s, t_list *lst, va_list vaarg)
{
	char	*str;
	int		i;

	str = ft_c_to_str(va_arg(vaarg, int), 1);
	if (!str)
		return (0);
	printf("%d", ft_atoi(s));
	ft_strlcat(str, ft_c_to_str(' ', ft_atoi(s) - 1), ft_atoi(s) - 1);
	ft_lstadd_back(&lst, ft_lstnew(str));
	i = 0;
	while (s[i] != 'c' && s[i])
		i++;
	return (i + 1);
}

int	ft_c_rightpad(char *s, t_list *lst, va_list vaarg)
{
	char	*str;
	int		i;

	str = ft_c_to_str(' ', ft_atoi(s) - 1);
	if (!str)
		return (0);
	ft_strlcat(str, ft_c_to_str(va_arg(vaarg, int), 1), ft_atoi(s) - 1);
	ft_lstadd_back(&lst, ft_lstnew(str));
	i = 0;
	while (s[i] != 'c' && s[i])
		i++;
	return (i);
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
	else if (*s == '-' && '1' <= *(s + 1) && *(s + 1) <= '9')
		return (ft_c_leftpad(s + 1, lst, vaarg));
	else if ('1' <= *s && *s <= '9')
		return (ft_c_rightpad(s, lst, vaarg));
	return (0);
}
