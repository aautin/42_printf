/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/15 15:12:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_b.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	
	char myChar = 'A';

    printf("%c\n", myChar);    // A (no padding, no width specified)
    printf("%5c\n", myChar);   //    A (width specified as 5, padding added)
    printf("%-5c|\n", myChar);  // A    | (left-justified in a width of 5, padding added)
    printf("%10c|\n", myChar);

	return (0);
}
