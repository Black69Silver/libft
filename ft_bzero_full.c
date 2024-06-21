/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/10 13:04:07 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write 'n' NULL characters in string pointed to with '*s'. */

#include <stdio.h>
#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*adj_s;

	i = 0;
	adj_s = s;
	if (n != 0)
	{
		while (i < n)
		{
			adj_s[i] = '\0';
			i++;
		}
	}
}

int	main(void)
{
	// Test cases
	char	s[50] = "This is a string.h library function.";
	size_t	n;

	n = 1;

	// Display the initial buffer
	printf(" Initial string: %s\n", s);

	ft_bzero (s, n);
	// Display the buffer after using ft_bzero OR bzero
	printf("Function result: %s\n", s);

	return 0;
}
