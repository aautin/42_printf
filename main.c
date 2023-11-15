/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin < aautin@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:24 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 14:02:03 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 6;
	if (argc == 2)
	{
		printf("|%d|", printf(" biqwehr %c %d %s NULL %p", 48, 48,
				(char *) NULL, argv[1]));
		printf("\n");
		printf("|%d|", ft_printf(" biqwehr %c %d %s NULL %p", 48, 48,
				(char *) NULL, argv[1]));
	}
	return (0);
}
