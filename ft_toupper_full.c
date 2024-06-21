/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/13 18:47:59 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Conversion of 'c' from lower to upper case. */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	main(void)
{
	int	c;

	c = '!';
	printf("     Original character: %c.\n", c);
	printf("Written function result: %c.\n", ft_toupper(c));
	printf("Library function result: %c.\n", toupper(c));
	return (0);
}
