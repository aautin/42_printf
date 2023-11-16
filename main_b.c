/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/16 16:58:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_b.h"

int	main(int argc, char *argv[])
{
	// (void) argc;
	// (void) argv;

	// char myChar = 'A';

	// printf("%c|\n", myChar);    // A (no padding, no width specified)
	// printf("%-1c|\n", myChar);   //    A (width specified as 5, padding added)
	// printf("%-2c|\n", myChar);  // A    | (left-justified in a width of 5, padding added)
	// printf("%-c|\n", myChar);
	// printf("%4c|\n", myChar);

	if (argc == 2)
	{
		printf("|%d|\n", ft_printf("%-2c %2c %-2c", argv[1][0], argv[1][1], argv[1][2]));
		printf("|%d|\n", printf("%-2c %2c %-2c", argv[1][0], argv[1][1], argv[1][2]));
	}
	return (0);
}
