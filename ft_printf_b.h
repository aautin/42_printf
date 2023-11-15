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

int		ft_ctype(t_list *lst, va_list vaarg, char *s);
char	*ft_c_to_str(char c, int nb);

int		ft_tag(t_list *lst, va_list vaarg, char *s);
int		ft_tag_type(char *s);
int		ft_printlst(t_list *lst);
int		ft_printf(const char *s, ...);

#endif