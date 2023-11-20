/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_putstag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:00:15 by aautin            #+#    #+#             */
/*   Updated: 2023/11/20 04:29:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

void	ft_putstr_len(char *str, int *printed)
{
	int	i;

	if (!str)
		ft_putstr_len("(null)", printed);
	else
	{
		i = 0;
		while (str[i])
		{
			ft_putchar_len(str[i], printed);
			i++;
		}
	}
}

void	ft_putstag(t_tag *tag)
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	str = va_arg(tag->vaarg, char *);
	len = ft_strlen(str);
	if (tag->pre < len && tag->pre > -1)
		len = tag->pre;
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
	while (++i < len && tag->pre != -2)
		ft_putchar_len(str[i], &tag->len);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
}
