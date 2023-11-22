/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_putdtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 05:05:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/21 19:31:08 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

static void	ft_insert(t_tag *tag, char *s, size_t nbsize)
{
	size_t	i;

	if (tag->plus || tag->space)										// countsignplusspace
		nbsize++;
	if (nbsize < (size_t) tag->wi && !tag->minus && tag->zero == ' ')	// leftwidthspace
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
	if (tag->plus && s[0] != '-')										// signplus
		ft_putchar_len('+', &tag->len);
	if (s[0] == '-')													// signminus
		ft_putchar_len('-', &tag->len);
	if (nbsize < (size_t) tag->wi && !tag->minus && tag->zero == '0')	// leftwidthzero
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
	if (tag->space && s[0] != '-')										// signspace
		ft_putchar_len(' ', &tag->len);
	if ((size_t) tag->pre > ft_strlen(s) - (s[0] == '-') && tag->pre != -1)		// precision
		ft_putcharnb_len('0', (size_t) tag->pre - ft_strlen(s) + (s[0] == '-'), &tag->len);
	i = -1;
	while (s[++i])														// number (nosign)
		if (s[i] != '-')
			ft_putchar_len(s[i], &tag->len);
	if (nbsize < (size_t) tag->wi && tag->minus)						// right_width
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
}

void		ft_putdtag(t_tag *tag)
{
	char	*str;

	str = ft_itoa(va_arg(tag->vaarg, int));
	if (tag->pre != -1 && (size_t) tag->pre > ft_strlen(str))			// definedpre > nb : pre
		ft_insert(tag, str, tag->pre);
	else																// else : strlen
		ft_insert(tag, str, ft_strlen(str));
	free(str);
}
