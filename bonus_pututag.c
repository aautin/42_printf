/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pututag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 05:05:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/22 17:02:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

static int	ft_nb_size(unsigned int n)
{
	int		i;
	int		temp;

	i = 1;
	temp = n / 10;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static char	*ft_utoa(unsigned int n)
{
	char	*array;
	int		i;
	int		sign;

	i = ft_nb_size(n);
	array = (char *)malloc((i + 1) * sizeof(char));
	if (!array)
		return (NULL);
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	array[i] = '\0';
	while (i--)
	{
		array[i] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		array[0] = '-';
	return (array);
}

static void	ft_insert(t_tag *tag, char *s, size_t nbsize)
{
	size_t	i;

	if (s[0] == '0' && tag->pre == 0)
	{
		s[0] = '\0';
		nbsize = 0;
		tag->zero = ' ';
	}
	if (tag->pre != -1)
		tag->zero = ' ';	
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

void		ft_pututag(t_tag *tag)
{
	char	*str;

	str = ft_utoa(va_arg(tag->vaarg, unsigned int));
	if (tag->pre != -1 && (size_t) tag->pre > ft_strlen(str))			// definedpre > nb : pre
		ft_insert(tag, str, tag->pre);
	else																// else : strlen
		ft_insert(tag, str, ft_strlen(str));
	free(str);
}
