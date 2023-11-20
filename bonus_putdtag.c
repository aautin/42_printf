/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_putdtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 05:05:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/20 05:30:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

void	ft_putdtag(t_tag *tag)
{
	char	*str;
	int		nb;
	int		len;

	str = ft_itoa(va_arg(tag->vaarg, int));
	len = ft_strlen(str);
	nb = -1;
	ft_pre_str(&nb, tag, len);
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
	if (nb != -1)
		ft_putcharnb_len('0', -nb - 1, &tag->len);
	nb = -1;
	while (++nb < len)
		ft_putchar_len(str[nb], &tag->len);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
	free(str);
}
