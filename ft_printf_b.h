/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:36 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 15:27:28 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_B_H
# define FT_PRINTF_B_H

# include "libft/libft.h"
# include <stdarg.h>

char	*ft_c_to_str(char c);
int		ft_printf(const char *s, ...);

#endif