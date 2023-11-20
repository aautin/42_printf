/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_putxtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:04:42 by aautin            #+#    #+#             */
/*   Updated: 2023/11/20 23:24:36 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

void	ft_puthexa_len(unsigned int nb, int *len, int maj, char *str)
{
	char	*hexabase;

	if (maj)
		hexabase = "0123456789ABCDEF";
	else
		hexabase = "0123456789abcdef";
	if (nb < 16)
		ft_strlcat_c(str, hexabase[nb]);
	else
	{
		ft_puthexa_len(nb / 16, len, maj, str);
		ft_strlcat_c(str, hexabase[nb % 16]);
	}
}

void	ft_insertxtag(t_tag *tag, int len, char *str)
{
	int	nb;

	if (tag->hastag)
		tag->wi -= 2;
	if (tag->hastag && tag->minus)
		ft_putstr_len("0x", &tag->len);
	nb = -1;
	ft_pre_str(&nb, tag, len);
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
	if (tag->hastag && !tag->minus)
		ft_putstr_len("0x", &tag->len);
	if (nb != -1)
		ft_putcharnb_len('0', -nb - 1, &tag->len);
	nb = -1;
	while (++nb < len)
		ft_putchar_len(str[nb], &tag->len);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
}

void	ft_putxtag(t_tag *tag, int maj)
{
	char	*str;
	int		nb;

	nb = va_arg(tag->vaarg, unsigned int);
	str = (char *)malloc((ft_nblen(nb, 16) + 1) * sizeof(char));
	str[0] = '\0';
	if (!str)
		return ;
	ft_puthexa_len(nb, &tag->len, maj, str);
	ft_insertxtag(tag, ft_strlen(str), str);
	free(str);
}
