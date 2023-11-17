/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:36 by aautin            #+#    #+#             */
/*   Updated: 2023/11/17 20:30:49 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_FT_PRINTF_H
# define BONUS_FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h> // to DELETE !!!

typedef struct s_tag
{
	va_list	vaarg;
	int		len;
	int		i;
	int		start;
	char	minus;
	char	plus;
	char	space;
	char	hastag;
	char	zero;
	int		wi;
	int		pre;
}	t_tag;

void	ft_putctag(char *src, t_tag *tag);
void	ft_putnotag(char *s, t_tag *tag);
void	ft_tags_init(t_tag *tags);
void	ft_putchar_len(int a, int *len);
void	ft_tags_def(char *src, t_tag *tag);
void	ft_tags_insert(char *src, t_tag * tag);

int		ft_nblen(int i);
int		ft_printf(const char *s, ...);

#endif