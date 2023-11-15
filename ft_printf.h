/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin < aautin@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 13:49:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void	ft_putchar_len(int a, int *printed);
void	ft_putnbr_len(int nb, int *printed);
void	ft_putunsign_len(unsigned int n, int *printed);
void	ft_putstr_len(char *str, int *printed);
void	ft_putptr_len(unsigned long long adress, int *printed);
void	ft_puthexa_len(unsigned long long nb, int *printed, int maj);
int		ft_printf(const char *str, ...);

#endif