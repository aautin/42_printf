/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:18 by aautin            #+#    #+#             */
/*   Updated: 2023/11/17 20:35:01 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

void	ft_putchar_len(int a, int *len)
{
	ft_putchar_fd(a, 1);
	*len += 1;
}

void	ft_tags_init(t_tag *tag)
{
	tag->start = tag->i;
	tag->minus = 0;
	tag->plus = 0;
	tag->space = 0;
	tag->hastag = 0;
	tag->zero = 0;
	tag->wi = 0;
	tag->pre = 0;
}

int		ft_nblen(int i)
{
	int	len;

	len = 1;
	while (i / 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_putnotag(char *s, t_tag *tag)
{	
	while (tag->start <= tag->i)
	{
		
		if (tag->pre == -1 && s[tag->start] == '.')
		{
			ft_putchar_len(s[tag->start], &tag->len);
			ft_putchar_len('0', &tag->len);
		}
		else
			ft_putchar_len(s[tag->start], &tag->len);
		tag->start++;
	}
}

void	ft_putctag(char *src, t_tag *tag)
{
	if (tag->wi)
		tag->pre = 0;
	while (tag->wi-- > 1)
		ft_putchar_len(' ', &tag->len);
	ft_putchar_len(va_arg(tag->vaarg, int), &tag->len);
	while (tag->pre-- > 1)
		ft_putchar_len(' ', &tag->len);
}

void	ft_tags_insert(char *s, t_tag *tag)
{
	if (!ft_strchr("cspdiuxX%", s[tag->i]))
		ft_putnotag(s, tag);
	else if (s[tag->i] == 'c')
		ft_putctag(s, tag);
	// else if (s[tag->i] == 's')
	// 	ft_putstag(s, tag);
	// else if (s[tag->i] == 'p')
	// 	ft_putptag(s, tag);
	// else if (s[tag->i] == 'i' && s[tag->i] == 'd')
	// 	ft_putdtag(s, tag);
	// else if (s[tag->i] == 'u')
	// 	ft_pututag(s, tag);
	// else if (s[tag->i] == 'x')
	// 	ft_putxtag(s, tag);
	// else if (s[tag->i] == 'X')
	// 	ft_putXtag(s, tag);
	else if (s[tag->i] == '%')
		ft_putchar_len('s', &tag->len);
}

void	ft_tags_def(char *src, t_tag *tag)
{
	while (ft_strchr("-+ #0", src[++tag->i]))
	{
		if (src[tag->i] == '-')
			tag->minus++;
		if (src[tag->i] == '+')
			tag->plus++;
		if (src[tag->i] == ' ')
			tag->space++;
		if (src[tag->i] == '#')
			tag->hastag++;
		if (src[tag->i] == '0')
			tag->zero++;
	}
	if (ft_isdigit(src[tag->i]))
	{
		tag->wi = ft_atoi(&src[tag->i]);
		tag->i += ft_nblen(tag->wi); 
	}
	if (ft_strchr(&src[tag->i], '.') && !ft_isdigit(src[tag->i + 1]))
	{
		tag->pre = -1;
		tag->i += 1;
	}
	if (ft_strchr(&src[tag->i], '.') && ft_isdigit(src[tag->i + 1]))
	{
		tag->pre += ft_atoi(&src[tag->i + 1]);
		tag->i += ft_nblen(tag->pre) + 1;
	}
}

int		ft_printf(const char *s, ...)
{
	t_tag	tag;

	tag.i = 0;
	tag.len = 0;
	va_start(tag.vaarg, s);
	while (s[tag.i])
	{
		if (s[tag.i] == '%' && s[tag.i + 1] != '\0')
		{
			ft_tags_init(&tag);
			ft_tags_def((char *) &s[0], &tag);
			ft_tags_insert((char *) &s[0], &tag);
		}
		else
			ft_putchar_len(s[tag.i], &(tag.len));
		if (s[tag.i])
			tag.i++;
	}
	va_end(tag.vaarg);
	return (tag.len);
}
