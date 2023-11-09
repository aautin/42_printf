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

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

char	*ft_ftoa(float i);
char	*ft_ctoa(char c, int size);
char	ft_tag_format(char *str, int i);
int	    ft_print_result(t_list *lst);
int	    ft_str_analyser(char *str, int *i, t_list *lst, va_list arg);
int	    ft_printf(const char *str, ...);
char	*ft_vaarg_to_str(va_list arg, char tag, char tag_sz);
char	*ft_tag_to_str(va_list arg, int *i, char *str);

#endif