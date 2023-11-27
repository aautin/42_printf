/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/08/10 13:42:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	*ptr;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == (char) c)
			pos = i;
		i++;
	}
	if ((char) c == '\0')
	{
		ptr = (char *) &s[i];
		return (ptr);
	}
	if (pos != -1)
	{
		ptr = (char *) &s[pos];
		return (ptr);
	}
	return (NULL);
}
