/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/18 16:04:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ft_printf.h"

int	main(int argc, char *argv[])
{
	// (void) argc;
	// (void) argv;
	// int num = 123;
	// int numgrd = 123456789;
	// printf("Testing tag with %%d:\n");
	// printf("%d|\n", num);           // Affichage de base
	// printf("%6d|\n", num);          // Largeur de champ de 6
	// printf("%6d|\n", numgrd);       // Largeur de champ de 6
	// printf("%06d|\n", num);         // Largeur de champ de 6 + rempli de 0
	// printf("%-6d|\n", num);         // Alignement à gauche
	// printf("%-6d|\n", numgrd);      // Alignement à gauche
	// printf("%+d|\n", num);          // Affichage du signe
	// printf("%0+6d|\n", num);        // Zéros + largeur de champ + affichage du signe
	// printf("%+06d|\n", num);        // Zéros + largeur de champ + affichage du signe
	// printf("% d|\n", num);          // Espace pour les positifs

	// printf("\nTesting tag with %%i:\n");
	// printf("%i|\n", num);           // Affichage de base
	// printf("%6i|\n", num);          // Largeur de champ de 6
	// printf("%6i|\n", numgrd);       // Largeur de champ de 6
	// printf("%06i|\n", num);         // Largeur de champ de 6 + rempli de 0
	// printf("%-6i|\n", num);         // Alignement à gauche
	// printf("%-6i|\n", numgrd);      // Alignement à gauche
	// printf("%+i|\n", num);          // Affichage du signe
	// printf("%0+6i|\n", num);        // Zéros + largeur de champ + affichage du signe
	// printf("%+06i|\n", num);        // Zéros + largeur de champ + affichage du signe
	// printf("% i|\n", num);          // Espace pour les positifs

	if (argc == 3)
	{
		printf("|%d\n", ft_printf(argv[1], argv[2])); 
		printf("|%d\n", printf(argv[1], argv[2]));
	}
	return (0);
}
