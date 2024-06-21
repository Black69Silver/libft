/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 15:19:25 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare not more than 'n' characters in strings 's1' and 's2'
 * without going beyond '\0' in any of them. The return value is
 * the difference in ASCII values of first different characters. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
	{
		printf("%zu-th character is '%c'.\n", i, s1[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	main(void)
{
	const char	s1[] = "The quick brown fox jumps over the lazy dog.";
	const char	s2[] = "The quick brown fox\0 jumps over the lazy dog.";
	size_t		n;

	n = 33;
	printf("Compare up to %zu characters of '%s & '%s'.\n", n, s1, s2);
	printf("Written funciton result: %d.\n", ft_strncmp(s1, s2, n));
	printf("Library funciton result: %d.\n", strncmp(s1, s2, n));
	return (0);
}
