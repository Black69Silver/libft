/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/13 20:14:34 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Conversion of 'c' from upper to lower case. */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int	main(void)
{
	int	c;

	c = 'z';
	printf("     Original character: %c.\n", c);
	printf("Written function result: %c.\n", ft_tolower(c));
	printf("Library function result: %c.\n", tolower(c));
	return (0);
}
