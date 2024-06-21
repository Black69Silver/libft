/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:24:15 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare unsigned chars in byte string 's1' against byte string 's2'.
 * Both strings are assumed to be 'n' bytes long. 
 * ~~Store the result in a 16 bit variable or you may get incorrect results
 * ~~if you use an unsigned char or char due to truncation.
 * Return the difference between the first two differing bytes. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	printf("i: %zu, str1: %d, str2: %d\n", i, str1[i], str2[i]);
	printf("i: %zu, str1: %c, str2: %c\n", i, str1[i], str2[i]);
	return (str1[i] - str2[i]);
}

int	main(void)
{
	const void	*s1;
	const void	*s2;
	size_t 		n;

//	s1 = "The quick brown fox jumps over the lazy dog.";
//	s2 = "The quick brown\0 fox jumps over the lazy dog.";
//	n = 100;
//	s1 = "abcdefghij";
//	s1 = "zyxbcdefgh";
//	s2 = "abcdefgxyz";
//	n = 7;
	s1 = NULL;
	s2 = NULL;
//	s1 = "test";
//	n = 4;
//	s1 = "\xff\xaa\xde\x12";
//	s2 = "\xff\xaa\xde\x12MACOSAAAAA";
//	n = 4;
//	s2 = "\xff\xaa\xde\xffMACOSX\xff";
//	s1 = "\xff\xaa\xde\x02";
	n = 1;
	printf("Expected: %d\n", memcmp(s1, s2, n));
	printf("  Actual: %d\n", ft_memcmp(s1, s2, n));
	return (0);
}
